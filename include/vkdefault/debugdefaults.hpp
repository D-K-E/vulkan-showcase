// some sane defaults for debugging utilities for vulkan api
#pragma once

#include <external.hpp>
#include <vkdebug/debug.hpp>

namespace vtuto {

VKAPI_ATTR VkBool32 VKAPI_CALL
debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
              VkDebugUtilsMessageTypeFlagsEXT messageType,
              const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
              void *pUserData) {
  std::cerr << messageSeverity
            << "validation layer output: " << pCallbackData->pMessage
            << std::endl;
  return VK_FALSE;
}

DebugUtilsCreateInfoExt mkDebugCreateInfo() {
  DebugUtilsCreateInfoExt cinfo;

  // severity level info
  cinfo.severity_flags.push_back(VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT);

  // message type: validation and performance
  cinfo.message_type_bits.push_back(
      VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT);
  cinfo.message_type_bits.push_back(
      VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT);

  // apply callback function
  cinfo.callbackFn = debugCallback;

  return cinfo;
}

} // namespace vtuto
