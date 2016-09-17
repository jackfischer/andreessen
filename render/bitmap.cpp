#include "bitmap.h"
#include <fstream>

BMP::BMP(const char *path)
{
    /* open file and check for error */
    std::fstream file(path, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        throw std::invalid_argument("bad file name");
    }

    /* move to end to grab file size */
    file.seekg(0, std::ios::end);
    std::size_t len = file.tellg();

    file.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> fileinfo(len);

    /* reads fileheader and info header (54 bytes) */
    /* see http://ccm.net/contents/732-the-bmp-format */
    file.read(reinterpret_cast<char *>(fileinfo.data()), 54);

    /* close on bad file signature */
    if (fileinfo[0] != 'B' && fileinfo[1] != 'M') {
        file.close();
        throw std::invalid_argument("needs bitmap file");
    }

    /* close on bad file format */
    if (fileinfo[28] != 24 && fileinfo[28] != 32) {
        file.close();
        throw std::invalid_argument("24 or 32 bit image only");
    }

    pxlbits = fileinfo[28];
    width = fileinfo[18] + (fileinfo[19] << 8);
    height = fileinfo[22] + (fileinfo[23] << 8);
    std::uint32_t pxlsoffset = fileinfo[10] + (fileinfo[11] << 8);

    std::uint32_t size = ((width * pxlbits + 31) / 32) * 4 * height;
    pxls.resize(size);

    file.seekg(pxlsoffset, std::ios::beg);
    file.read(reinterpret_cast<char *>(pxls.data()), size);
    file.close();

}
