#include "freertos/FreeRTOS.h" // FreeRTOS core
#include "freertos/task.h" // Task APIs
#include "driver/gpio.h" // GPIO control
#include "esp_log.h" // Logging
#include "esp_http_server.h" // HTTP server

#define LED_GPIO GPIO_NUM_2 // On many ESP32 boards, GPIO2 drives onboard LED

static const char *TAG = "WEB"; // Log tag
static int led_state = 0; // LED state cache

static esp_err_t root_get_handler(httpd_req_t *req) { // HTTP GET handler for root
  const char *resp = led_state ? "LED: ON\nUse /toggle to switch, /state to query" : "LED: OFF\nUse /toggle to switch, /state to query"; // Prepare response text
  httpd_resp_set_type(req, "text/plain"); // Set content type
  httpd_resp_send(req, resp, HTTPD_RESP_USE_STRLEN); // Send response
  return ESP_OK; // Indicate success
} // End handler

static esp_err_t toggle_get_handler(httpd_req_t *req) { // HTTP GET handler to toggle LED
  led_state = !led_state; // Flip LED state
  gpio_set_level(LED_GPIO, led_state); // Apply new state to GPIO
  httpd_resp_set_type(req, "application/json"); // JSON response
  const char *ok = led_state ? "{\"led\":1}" : "{\"led\":0}"; // Build JSON
  httpd_resp_send(req, ok, HTTPD_RESP_USE_STRLEN); // Send response
  return ESP_OK; // OK
} // End handler

static esp_err_t state_get_handler(httpd_req_t *req) { // Report LED state
  httpd_resp_set_type(req, "application/json"); // JSON
  const char *body = led_state ? "{\"led\":1}" : "{\"led\":0}"; // Body
  httpd_resp_send(req, body, HTTPD_RESP_USE_STRLEN); // Send
  return ESP_OK; // OK
} // End handler

static httpd_handle_t start_webserver(void) { // Start HTTP server
  httpd_config_t config = HTTPD_DEFAULT_CONFIG(); // Default config
  httpd_handle_t server = NULL; // Server handle
  if (httpd_start(&server, &config) == ESP_OK) { // Start server
    httpd_uri_t root = { .uri = "/", .method = HTTP_GET, .handler = root_get_handler, .user_ctx = NULL }; // Root route
    httpd_register_uri_handler(server, &root); // Register root
    httpd_uri_t toggle = { .uri = "/toggle", .method = HTTP_GET, .handler = toggle_get_handler, .user_ctx = NULL }; // Toggle route
    httpd_register_uri_handler(server, &toggle); // Register toggle
    httpd_uri_t state = { .uri = "/state", .method = HTTP_GET, .handler = state_get_handler, .user_ctx = NULL }; // State route
    httpd_register_uri_handler(server, &state); // Register state
  } // End if
  return server; // Return server handle
} // End start_webserver

void app_main(void) { // Application entry
  gpio_reset_pin(LED_GPIO); // Reset LED pin
  gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT); // Set as output
  gpio_set_level(LED_GPIO, led_state); // Initialize state
  ESP_LOGI(TAG, "Starting web server"); // Log start
  (void)start_webserver(); // Start HTTP server
  while (true) { vTaskDelay(pdMS_TO_TICKS(1000)); } // Keep running
} // End app_main

