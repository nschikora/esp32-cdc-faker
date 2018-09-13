class CDChanger {

public:
    CDChanger();
    ~CDChanger();

    void startup();

    static CDChanger& instance();
};