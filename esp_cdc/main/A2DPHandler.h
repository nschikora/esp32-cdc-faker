#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "esp_a2dp_api.h"
#include "esp_avrc_api.h"
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"
#include "freertos/task.h"
#include "esp_gap_bt_api.h"


#define BT_APP_SIG_WORK_DISPATCH (0x01)

/* event for handler "bt_av_hdl_stack_up */
enum {
    BT_APP_EVT_STACK_UP = 0,
};

/* handler for the dispatched work */
typedef void (* bt_app_cb_t) (uint16_t event, void *param);

/* message to be sent */
typedef struct {
    uint16_t             sig;      // signal to bt_app_task
    uint16_t             event;    // message event id
    bt_app_cb_t          cb;       // context switch callback
    void                 *param;   // parameter area needs to be last
} bt_app_msg_t;

/* parameter deep-copy function to be customized */
typedef void (* bt_app_copy_cb_t) (bt_app_msg_t *msg, void *p_dest, void *p_src);

class A2DPHandler {
    A2DPHandler();
public:
    ~A2DPHandler();

    uint32_t m_pkt_cnt;
    esp_a2d_audio_state_t m_audio_state;
    xQueueHandle bt_app_task_queue;
    xTaskHandle bt_app_task_handle;

    static A2DPHandler& instance();

    void startup();
    /* handler for bluetooth stack enabled events */
    static void bt_av_hdl_stack_evt(uint16_t event, void *p_param);
    /* callback function for A2DP sink */
    static void bt_app_a2d_cb(esp_a2d_cb_event_t event, esp_a2d_cb_param_t *param);
    /* callback function for A2DP sink audio data stream */
    static void bt_app_a2d_data_cb(const uint8_t *data, uint32_t len);
    /* callback function for AVRCP controller */
    static void bt_app_rc_ct_cb(esp_avrc_ct_cb_event_t event, esp_avrc_ct_cb_param_t *param);
    /* a2dp event handler */
    static void bt_av_hdl_a2d_evt(uint16_t event, void *p_param);
    /* avrc event handler */
    static void bt_av_hdl_avrc_evt(uint16_t event, void *p_param);
    /* gap event handler */
    static void bt_app_gap_cb(esp_bt_gap_cb_event_t event, esp_bt_gap_cb_param_t *param);
    static void bt_app_alloc_meta_buffer(esp_avrc_ct_cb_param_t *param);
    static void bt_av_new_track();
    static void bt_av_notify_evt_handler(uint8_t event_id, uint32_t event_parameter);
    /* work dispatcher for the application task */
    static bool bt_app_work_dispatch(bt_app_cb_t p_cback, uint16_t event, void *p_params, int param_len, bt_app_copy_cb_t p_copy_cback);
    static void bt_app_task_start_up(void);
    static void bt_app_task_shut_down(void);
    static void bt_app_task_handler(void *arg);
    static bool bt_app_send_msg(bt_app_msg_t *msg);
    static void bt_app_work_dispatched(bt_app_msg_t *msg);

};