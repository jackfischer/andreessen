#include <vector>
#include <cstdint>

class BMP
{
    private:
        std::uint32_t width;
        std::uint32_t height;
        std::uint32_t pxlbits;
        std::vector<std::uint8_t> pxls;
    public:
        BMP(const char *path);
        std::vector<std::uint8_t> getPixels() const {return this->pxls;}
        std::uint32_t getWidth() const {return this->width;}
        std::uint32_t getHeight() const {return this->height;}
        bool alpha() {return pxlbits == 32;}
};
