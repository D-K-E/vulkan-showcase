// some sane defaults for debugging utilities for vulkan api
#pragma once

#include <external.hpp>
#include <vkdebug/debug.hpp>

namespace vtuto {

static VkBool32 VKAPI_CALL
debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
              VkDebugUtilsMessageTypeFlagsEXT messageType,
              const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
              void *pUserData) {
  std::cerr << "Severity: " << messageSeverity
            << "validation layer output: " << pCallbackData->pMessage
            << std::endl;
  return VK_FALSE;
}

VkDebugUtilsMessengerCreateInfoEXT mkDebugCreateInfo() {
  DebugUtilsCreateInfoExt cinfo;

  // severity level info
  cinfo.severity_flags.push_back(VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT);
  cinfo.severity_flags.push_back(VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT);
  cinfo.severity_flags.push_back(VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT);

  // message type: validation and performance

  cinfo.message_type_bits.push_back(
      VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT);
  cinfo.message_type_bits.push_back(
      VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT);
  cinfo.message_type_bits.push_back(
      VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT);

  // apply callback function
  cinfo.callbackFn = debugCallback;

  return cinfo.mkDebugMessengerInfo();
}

static VkDebugUtilsMessengerCreateInfoEXT DebugINFO = mkDebugCreateInfo();

void mkDebugMess(VkInstance &instance, VkDebugUtilsMessengerEXT &messenger) {
  //
  auto res = createDebugMessenger(instance, DebugINFO, messenger);
  std::string msg = "Failed to create default Vulkan debug messenger";
  UPDATE_RESULT_VK(res, msg);
}

} // namespace vtuto
