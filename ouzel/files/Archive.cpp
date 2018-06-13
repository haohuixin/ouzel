// Copyright (C) 2018 Elviss Strazdins
// This file is part of the Ouzel engine.

#include <stdexcept>
#include "Archive.hpp"
#include "FileSystem.hpp"
#include "core/Engine.hpp"
#include "utils/Log.hpp"
#include "utils/Utils.hpp"

namespace ouzel
{
    Archive::Archive(const std::string& filename)
    {
        file = File(engine->getFileSystem()->getPath(filename), File::READ);

        for (;;)
        {
            uint32_t signature;

            file.readAll(&signature, sizeof(signature));

            if (decodeUInt32Little(&signature) == 0x02014b50) // central directory
                break;

            if (decodeUInt32Little(&signature) != 0x04034b50)
                throw std::runtime_error("Bad signature");

            uint8_t version[2];

            file.readAll(version, sizeof(version));

            uint16_t flags;

            file.readAll(&flags, sizeof(flags));

            uint16_t compression;
            file.readAll(&compression, sizeof(compression));

            if (compression != 0x00)
                throw std::runtime_error("Unsupported compression");

            file.seek(4, File::CURRENT); // skip modification time
            file.seek(4, File::CURRENT); // skip CRC-32

            uint32_t compressedSize;
            file.readAll(&compressedSize, sizeof(compressedSize));

            uint32_t uncompressedSize;
            file.readAll(&uncompressedSize, sizeof(uncompressedSize));

            uint16_t fileNameLength;
            file.readAll(&fileNameLength, sizeof(fileNameLength));

            uint16_t extraFieldLength;
            file.readAll(&extraFieldLength, sizeof(extraFieldLength));

            std::vector<char> name(decodeUInt16Little(&fileNameLength) + 1);

            file.readAll(name.data(), decodeUInt16Little(&fileNameLength));

            name[decodeUInt16Little(&fileNameLength)] = '\0';

            Entry& entry = entries[name.data()];
            entry.size = decodeUInt32Little(&uncompressedSize);

            file.seek(decodeUInt16Little(&extraFieldLength), File::CURRENT); // skip extra field

            entry.offset = file.getOffset();

            file.seek(decodeInt32Little(&uncompressedSize), File::CURRENT); // skip uncompressed size
        }
    }

    Archive::~Archive()
    {
        if (fileSystem) fileSystem->removeArchive(this);
    }

    Archive::Archive(Archive&& other)
    {
        if (other.fileSystem)
        {
            other.fileSystem->addArchive(this);
            other.fileSystem->removeArchive(&other);
        }

        file = std::move(other.file);
        entries = std::move(other.entries);
    }

    Archive& Archive::operator=(Archive&& other)
    {
        if (&other != this)
        {
            if (fileSystem) fileSystem->removeArchive(this);

            if (other.fileSystem)
            {
                other.fileSystem->addArchive(this);
                other.fileSystem->removeArchive(&other);
            }

            fileSystem = other.fileSystem;
            file = std::move(other.file);
            entries = std::move(other.entries);
        }

        return *this;
    }

    bool Archive::readFile(const std::string& filename, std::vector<uint8_t>& data) const
    {
        auto i = entries.find(filename);

        if (i == entries.end()) return false;

        file.seek(static_cast<int32_t>(i->second.offset), File::BEGIN);

        data.resize(i->second.size);

        file.readAll(data.data(), i->second.size);

        return true;
    }

    bool Archive::fileExists(const std::string& filename) const
    {
        return entries.find(filename) != entries.end();
    }
}
