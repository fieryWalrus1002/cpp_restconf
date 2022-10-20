#ifndef DEVINTERFACE_H
#define DEVINTERFACE_H

#include <curlhandle.h>

#include <json.hpp>

namespace devinterface {

  /**  Device classes to be used with devquery */
  enum class DeviceCode { CISCO_IOSXE, SNMPV3 };

  /**
   * @brief A class for querying devices with different protocols
   */
  class DevInterface {

  public:
    
    /**
     * @brief Queries the device with the given device class
     * @param query The query to send to the device, e.g. "CiscoIOS-XE::clientOperData;"
     * @return The result of the query, in json format
     */
    std::string get(std::string query);
  };

}  // namespace devinterface

#endif
