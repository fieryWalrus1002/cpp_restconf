#include <curlhandle.h>

namespace devinterface {

  typedef std::unique_ptr<CURL, std::function<void(CURL*)>> CURL_ptr;

  /**
   * @brief Curl Handle for the devinterface API. Does the actual https work.
   *
   *
   */

  class CurlHandle {
  private:
    CURL_ptr curlptr;
    constexpr static auto deleter = [](CURL* c) {
      curl_easy_cleanup(c);
      curl_global_cleanup();
    };

  public:
    /**
     * @brief Construct a new Curl Handle object with custom deleter
     *
     */
    CurlHandle() : curlptr(curl_easy_init(), deleter) { curl_global_init(CURL_GLOBAL_ALL); }

    /**
     * @brief Get the CURLcode object
     *
     * @return CURLcode
     */
    CURLcode Fetch() { return curl_easy_perform(curlptr.get()); }
  };

};  // namespace devinterface