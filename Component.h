//
// Created by utec on 28/06/19.
//

#ifndef UNTITLED15_COMPONENT_H
#define UNTITLED15_COMPONENT_H

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Event{
    int x;
    int y;
public:
    Event(int x, int y): x{x}, y{y}{};
    int getX(){return x;};
    int getY(){return y;};
};


class Component{
public:
    function<void(Event)> clickEvent;
    function<void(Event)> mouseMoveEvent;
    void onClick(function<void(Event)> f){clickEvent = f;};
    void onMouseMove (function<void(Event)> f){mouseMoveEvent = f};
    virtual void draw() = 0;
};

class Circle: public Component{
    int x;
    int y;
    int w;
    int h;
public:
    Circle(int x, int y, int w, int h):x{x},y{y},w{w},h{h}{
    };
};

class Rectangle: public Component{
    int x;
    int y;
    int w;
    int h;
    Rectangle(int x, int y, int w, int h):x{x},y{y},w{w},h{h}{
    };
};

struct Mouse{
    int x;
    int y;
    bool click;
    bool move;
};

class Window{
    vector<Component*> controls;
    Mouse mouse;
    bool close;
    Event* event = nullptr;
public:

    void start(){
        //Se crean y se setean las funciones
    }

    void run(){
        while(true) {
            cin>>mouse.click;
            if(mouse.click){
                delete event;
                event = new Event(mouse.x, mouse.y);
                for (auto com: controls)
                    com->clickEvent(*event);

            }

            cin>>mouse.move;
            if(mouse.move){
                delete event;
                event = new Event(mouse.x, mouse.y);
                for (auto com: controls)
                    com->mouseMoveEvent(*event);
            }

            cin>>close;
            if(close){
                break;
            }


        }
    };
    void addComponent(Component* com){controls.push_back(com);};
    void removeComponent(Component* com){
        auto item = find(begin(controls), end(controls), com);

        if (item != end(controls))
            controls.erase(item);
    };
};

#endif //UNTITLED15_COMPONENT_H
