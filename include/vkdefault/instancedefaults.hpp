// vk instance defaults
#pragma once
#include <external.hpp>
#include <initvk/vkInstance.hpp>
#include <vkdefault/debugdefaults.hpp>

namespace vtuto {

/**
  \brief get required extensions from glfw and debug utils
  First we query glfw api for enabled extensions. Then we
  add the debug flag
  to enable validation layers.
 */
std::vector<const char *> getRequiredExtensions() {
  uint32_t glfwExtensionCount = 0;
  const char **glfwExtensions;
  glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

  // we reserve the size for the requested extensions
  // vector
  std::vector<const char *> extensions(glfwExtensions,
                                       glfwExtensions + glfwExtensionCount);
  if (enableValidationLayers) {
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
  }
  return extensions;
}

AppInfo_Vk_Params mkAppInfo() {
  //
  AppInfo_Vk_Params app;
  app.app_version[0] = 1;
  app.app_version[1] = 0;
  app.app_version[2] = 0;

  app.engine_version[0] = 1;
  app.engine_version[1] = 0;
  app.engine_version[2] = 0;

  app.app_name = "My Vulkan Application";
  app.engine_name = "Custom Engine";

  app.api_version = VK_API_VERSION_1_2;
  return app;
}

InstanceInfo_Vk_Params mkInstanceInfoParams() {

  InstanceInfo_Vk_Params params;
  params.extensions = getRequiredExtensions();
  std::vector<const char *> khronos_layers = {"VK_LAYER_KHRONOS_validation"};
  params.validation_layers = khronos_layers;
  return params;
}

static AppInfo_Vk_Params app_params = mkAppInfo();

static InstanceInfo_Vk_Params inst_params = mkInstanceInfoParams();

void mkInstance(VkInstance &instance) {

  //
  Result_Vk res;
  std::string msg = "Failed to create default Vulkan instance";
  res = createInstance(app_params, inst_params, DebugINFO, instance);
  UPDATE_RESULT_VK(res, msg);
}

/**make a default instance*/
VkInstance mkInstance() {
  VkInstance instance;
  mkInstance(instance);
  return instance;
}

} // namespace vtuto
