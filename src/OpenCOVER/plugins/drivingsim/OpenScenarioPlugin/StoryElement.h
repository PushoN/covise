#ifndef STORYELEMENT_H
#define STORYELEMENT_H


class StoryElement
{
public:
    StoryElement();
    enum State
    {
        finished,
        running,
        stopped
    };
    State state;

    void stop();
    void start();
    void finish();

    bool isRunning();
    bool isStopped();
    bool isFinished();
};

#endif // STORYELEMENT_H
