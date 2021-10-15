#pragma once

// graph like architecture
#include <external.hpp>
#include <vertex.hpp>
#include <vkgraph/vknode.hpp>

namespace vtuto {

struct vk_triapp {

  /** Attributes unrelated to vulkan
    @{
   */
  std::string win_title = "Vulkan Window Graph";
  uint32_t win_width = 800;
  uint32_t win_height = 600;

  GLFWwindow *window; // window for visualizing object.

  /** @} */

  /** instance of the vulkan application */
  VkInstance instance;

  /** debug callback function handler */
  VkDebugUtilsMessengerEXT debugMessenger;

  /** physical device pointer and related objects
   * @{
   */

  /** physical device handler */
  VkPhysicalDevice pdevice = VK_NULL_HANDLE;
  /** physical device windows surface */
  VkSurfaceKHR surface;
  /** @} */

  /** logical device pointer and related objects
    @{
   */

  /** logical device handler */
  VkDevice ldevice;

  /** graphics queue */
  VkQueue graphics_queue;

  /** window surface queue */
  VkQueue present_queue;
  /** @} */

  /** swap chain for handling frame rate
    It contains several handlers all dealing with
    frames
    @{
   */
  /** swapchain for handling frame rate*/
  VkSwapchainKHR chain;

  /** images in swap chain */
  std::vector<VkImage> simages;

  /** swapchain image format*/
  VkFormat simage_format;

  /** swapchain extent*/
  VkExtent2D sextent;

  /** swapchain image view */

  std::vector<VkImageView> views;

  /** @} */

  /** swap chain frame buffers
    @{
   */
  std::vector<VkFramebuffer> swapchain_framebuffers;

  /** @} */

  /** render pass @{ */

  VkRenderPass render_pass;

  /** @} */

  /** descriptor set layout @{ */
  VkDescriptorSetLayout descriptor_set_layout;

  /** @} */

  /** descriptor pool @{*/
  VkDescriptorPool descriptor_pool;

  /** @} */

  /** descriptor sets @{*/

  std::vector<VkDescriptorSet> descriptor_sets;

  /** @} */

  /** graphics pipeline layout @{*/
  VkPipelineLayout pipeline_layout;

  /** @} */

  /** graphics pipeline object @{*/

  VkPipeline graphics_pipeline;

  /** @} */

  /** command pool and command buffer handlers

    From spec: Command pools are externally synchronized,
    meaning that a
    command pool must not be used concurrently in multiple
    threads. That
    includes use via recording commands on any command
    buffers allocated from
    the pool, as well as operations that allocate, free, and
    reset command
    buffers or the pool itself.

    @{*/

  VkCommandPool pool;
  std::vector<VkCommandBuffer> cbuffers;
  std::vector<bool> available_cbuffers;

  /** @} */

  /** Texture related handlers @{*/

  /** staging buffer */

  VkBuffer staging_buffer;
  VkDeviceMemory stage_buffer_memory;
  VkImage texture_image;
  VkDeviceMemory texture_image_memory;

  /** texture image view */
  VkImageView texture_image_view;

  /** texture sampler */
  VkSampler texture_sampler;

  /** @} */

  /** depth image related @{*/
  VkImage depth_image;
  VkImageView depth_image_view;
  VkDeviceMemory depth_image_memory;

  /** @} */

  /** Scene dependent attributes
    @{
   */

  /** vertices per scene and indices per scene */

  std::vector<Vertex> vertices;
  std::vector<std::uint32_t> indices;

  /** vertex buffer */
  VkBuffer vertex_buffer;
  VkDeviceMemory vertex_buffer_memory;

  /** index buffer */
  VkBuffer index_buffer;
  VkDeviceMemory index_buffer_memory;

  /** uniform buffer */
  std::vector<VkBuffer> uniform_buffers;
  std::vector<VkDeviceMemory> uniform_buffer_memories;

  /** @} */

  /** Thread related objects and handlers
    @{
   */

  /** vk semaphore to hold available and rendered images */
  std::vector<VkSemaphore> image_available_semaphores;
  std::vector<VkSemaphore> render_finished_semaphores;

  /** fence image for drawing */
  std::vector<VkFence> current_fences;
  std::vector<VkFence> images_in_flight;
  std::size_t current_frame = 0;

  /** maximum frames in flight*/
  const int MAX_FRAMES_IN_FLIGHT = 2;

  /** @} */

  /** check framebuffer state*/
  bool framebuffer_resized = false;
};

} // namespace vtuto
