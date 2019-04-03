#pragma once
#include "ForClient.h"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
//#include <glm/ext/constants.hpp> // glm::pi


class ImgLayer : public boo::Layer
{
public:
    ImgLayer()
        : Layer("ImgLayer")
    {
    }

    void OnUpdate() override
    {
        BOO_CLIENT_INFO("ImgLayer::Update");
    }

    void OnEvent(boo::Event& onEvent) override
    {
        BOO_CLIENT_TRACE("{0}", onEvent);

        if (onEvent.GetEventType() == boo::EventType::KeyPressed)
        {
           
        }
    }
};

/* Helper Class to Test Key & Mouse Code BOO_ApiCode*/
class KeyCodeLayer : public boo::Layer
{
public:
    KeyCodeLayer()
        : Layer("KeyCodeLayer")
    {
    }

    void OnUpdate() override
    {
       // BOO_CLIENT_INFO("KeyCodeLayer::Update");

        if (boo::InputMgr::IsKeyPressed(BOO_KEY_TAB))
        {
            BOO_CLIENT_TRACE("Tab key Pressed");
        }

        if (boo::InputMgr::IsMouseButtonPressed(BOO_MOUSE_BUTTON_1))
        {
            BOO_CLIENT_TRACE("Button Pressed");
        }
    }

    void OnEvent(boo::Event& onEvent) override
    {
       // BOO_CLIENT_TRACE("{0}", onEvent);

        if (onEvent.GetEventType() == boo::EventType::KeyPressed)
        {
            boo::KeyPressedEvent& keyEvent = (boo::KeyPressedEvent&)onEvent;
            
            /*Comparison*/
            if (keyEvent.GetKeyCode() == BOO_KEY_W)
            {
                BOO_CLIENT_TRACE("Player Walking UP");
            }
            else if (keyEvent.GetKeyCode() == BOO_KEY_S)
            {
                BOO_CLIENT_TRACE("Player Walking Down");
            }
            else
            {
                BOO_CLIENT_TRACE("Player Is Not Moving!");
            }
            
            
            BOO_CLIENT_TRACE(" {0} ", (char)keyEvent.GetKeyCode());
        }
    }
};

class MathLayer : public boo::Layer
{
public:
    MathLayer()
        : Layer("MathLayer")
    {
        auto cam = camera(5.0f, { 0.5f, 0.5f });
    }

    void OnUpdate() override
    {
        //BOO_CLIENT_INFO("MathLayer::Update");

        //glm::mat4 camera(float Translate, glm::vec2 const& Rotate);

        //camera(5.0f, { 0.5f, 0.5f });
       
    }

    void OnEvent(boo::Event& onEvent) override
    {
        // BOO_CLIENT_TRACE("{0}", onEvent);

        if (onEvent.GetEventType() == boo::EventType::KeyPressed)
        {
            boo::KeyPressedEvent& keyEvent = (boo::KeyPressedEvent&)onEvent;

            /*Comparison*/
            if (keyEvent.GetKeyCode() == BOO_KEY_W)
            {
                BOO_CLIENT_TRACE("Player Walking UP");
            }
            else if (keyEvent.GetKeyCode() == BOO_KEY_S)
            {
                BOO_CLIENT_TRACE("Player Walking Down");
            }
            else
            {
                BOO_CLIENT_TRACE("Player Is Not Moving!");
            }


            BOO_CLIENT_TRACE(" {0} ", (char)keyEvent.GetKeyCode());
        }
    }

    glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
    {
        glm::mat4 Projection = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.f);
        glm::mat4 View       = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));

        View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
        View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));

        glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));

        return Projection * View * Model;
    }
};

