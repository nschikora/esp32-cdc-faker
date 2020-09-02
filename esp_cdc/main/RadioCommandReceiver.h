class RadioCommandReceiver {
public:
    static RadioCommandReceiver& getInstance() {
        static RadioCommandReceiver instance;
        return instance;
    }
    void startup();

private:
    RadioCommandReceiver();
    ~RadioCommandReceiver();
    RadioCommandReceiver(RadioCommandReceiver const&); // Don't Implement
    void operator=(RadioCommandReceiver const&); // Don't implement
    static void nec_rx_task();
};