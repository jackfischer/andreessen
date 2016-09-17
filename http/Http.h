#include <string>

class Http {
    public:
        // variables
        int sck;
        // functions
        void connect(std::string url);
        std::string makeRequest(const char *req);
};
