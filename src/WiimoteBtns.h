#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H

class WiimoteBtns {
    private:
        int fd;
    public:
        WiimoteBtns();

        ~WiimoteBtns();

        void listen();
};

#endif
