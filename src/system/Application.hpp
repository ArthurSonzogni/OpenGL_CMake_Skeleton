/**
 * Application.cpp
 * Contributors:
 *      * Arthur Sonzogni (author)
 * Licence:
 *      * MIT
 */

#ifndef APPLICATION_JX8NA5Y9
#define APPLICATION_JX8NA5Y9

#include <string>

class GLFWwindow;

class Application
{
    public:

        Application();

        static Application& getInstance();

        // get the window id
        GLFWwindow* getWindow() const;

        // window control
        void exit();

        // delta time between frame and time from beginning
        float getFrameDeltaTime() const;
        float getTime() const;

        // application run
        void run();

        // Application informations
        int getWidth();
        int getHeight();
        float getWindowRatio();
        bool windowDimensionChange();

    private:

        enum State {
            stateReady,
            stateRun,
            stateExit
        };

        State state;

        Application& operator=(const Application&) {return *this;}

        GLFWwindow* window;
        float time;
        float deltaTime;

        int width;
        int height;
        bool dimensionChange;
        void detectWindowDimensionChange();

    protected:

        Application(const Application&) {};

        std::string title;

        virtual void loop();

};

#endif /* end of include guard: APPLICATION_JX8NA5Y9 */
