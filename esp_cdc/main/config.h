#define CONFIG_A2DP_SINK_OUTPUT_EXTERNAL_I2S    1
#define CONFIG_A2DP_SINK_OUTPUT                 CONFIG_A2DP_SINK_OUTPUT_EXTERNAL_I2S

#define CONFIG_BT_DEV_NAME                      "ESP_SPEAKER"

#define BT_AV_TAG                               "BT_AV"
#define BT_APP_CORE_TAG                         "BT_APP_CORE"

#define CONFIG_I2S_LRCK_PIN                     22
#define CONFIG_I2S_BCK_PIN                      26
#define CONFIG_I2S_DATA_PIN                     25
#define CONFIG_I2S_PORT                         i2s_port_t::I2S_NUM_0
#define CONFIG_I2S_BITS_PER_SAMPLE              i2s_bits_per_sample_t::I2S_BITS_PER_SAMPLE_16BIT
#define CONFIG_I2S_CHANNELS                     i2s_channel_t::I2S_CHANNEL_STEREO
#define CONFIG_I2S_COMM_FORMAT                  i2s_comm_format_t::I2S_COMM_FORMAT_I2S_MSB
#define CONFIG_I2S_CHANNEL_FORMAT               i2s_channel_fmt_t::I2S_CHANNEL_FMT_RIGHT_LEFT

#define RCR_TAG                                 "RCR"
#define RMT_RX_ACTIVE_LEVEL                     1                                                   /*!< RMT active level (active high) */
#define RMT_RX_CHANNEL                          rmt_channel_t::RMT_CHANNEL_0                        /*!< RMT channel for receiver */
#define RMT_RX_GPIO_NUM                         gpio_num_t::GPIO_NUM_19                             /*!< GPIO number for receiver */
#define RMT_CLK_DIV                             100                                                 /*!< RMT counter clock divider */
#define RMT_TICK_10_US                          (80000000/RMT_CLK_DIV/100000)                       /*!< RMT counter value for 10 us.(Source clock is APB clock) */

#define NEC_HEADER_HIGH_US                      9000                                                /*!< NEC protocol header: positive 9ms */
#define NEC_HEADER_LOW_US                       4500                                                /*!< NEC protocol header: negative 4.5ms*/
#define NEC_BIT_ONE_HIGH_US                     560                                                 /*!< NEC protocol data bit 1: positive 0.56ms */
#define NEC_BIT_ONE_LOW_US                      (2250-NEC_BIT_ONE_HIGH_US)                          /*!< NEC protocol data bit 1: negative 1.69ms */
#define NEC_BIT_ZERO_HIGH_US                    560                                                 /*!< NEC protocol data bit 0: positive 0.56ms */
#define NEC_BIT_ZERO_LOW_US                     (1120-NEC_BIT_ZERO_HIGH_US)                         /*!< NEC protocol data bit 0: negative 0.56ms */
#define NEC_BIT_END                             560                                                 /*!< NEC protocol end: positive 0.56ms */
#define NEC_BIT_MARGIN                          20                                                  /*!< NEC parse margin time */
#define NEC_ITEM_DURATION(d)                    ((d & 0x7fff)*10/RMT_TICK_10_US)                    /*!< Parse duration time from memory register value */
#define NEC_DATA_ITEM_NUM                       34                                                  /*!< NEC code item number: header + 32bit data + end */
#define rmt_item32_tIMEOUT_US                   9500                                                /*!< RMT receiver timeout value(us) */