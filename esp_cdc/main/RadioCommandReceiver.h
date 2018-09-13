class RadioCommandReceiver {
public:
    RadioCommandReceiver();
    ~RadioCommandReceiver();

    void startup();
    static void nec_rx_task();

    static RadioCommandReceiver& instance();
};