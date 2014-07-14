#ifndef __GL_WINDOW1_H__
#define __GL_WINDOW1_H__


#include <ngl/Colour.h>
#include <ngl/Light.h>
#include <ngl/TransformStack.h>
#include <ngl/Text.h>
#include <ngl/Material.h>
#include <QTime>
#include <QEvent>
#include <QResizeEvent>
#include <ngl/VertexArrayObject.h>
#include "GLData.h"
#include "Object.h"
#include <ngl/Camera.h>
#include "PulseManager.h"
#include "Texture.h"

class GLWindow1 : public QGLWidget
{
Q_OBJECT        // must include this if you use Qt signals/slots
public :
  /// @brief Constructor for GLWindow
  /// @param [in] parent the parent window to create the GL context in
  GLWindow1(
           QWidget *_parent
          );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method that polygonise the object and builds a VAO ready to be rendered
  //----------------------------------------------------------------------------------------------------------------------
  void buildVAO(GLData *data);

  void buildVAOSphere(GLData *data);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method that load the hyperspectral data and changes the shader from Gold to texture
  //----------------------------------------------------------------------------------------------------------------------
  void loadHyperspectral(
          const std::string i_filename,
          const std::vector<unsigned short int> &i_bands
  );
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method that changes the type of the shader. Either texture or Gold
  //----------------------------------------------------------------------------------------------------------------------
  void changeShaderMode(bool i_shaderMode);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief method that processes the key events and ajusts the camera accordingly
  /// @param[in] i_event the event that indicated which button was pressed
  /// @param[in] i_step how much to rotate or move the camera
  //----------------------------------------------------------------------------------------------------------------------
  void processKeyPress(QKeyEvent *i_event, float i_step);
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief dtor
  //----------------------------------------------------------------------------------------------------------------------
  ~GLWindow1();
private :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief
  //----------------------------------------------------------------------------------------------------------------------
  ngl::VertexArrayObject *m_vao;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the vertices normals of the object
  //----------------------------------------------------------------------------------------------------------------------
  GLData m_glData;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the object that we want to polygonise and render in the GLWindow
  //----------------------------------------------------------------------------------------------------------------------
  Object *m_object;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief a simple light use to illuminate the screen
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Light *m_light;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the x rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_spinXFace;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief used to store the y rotation mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_spinYFace;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool m_rotate;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief flag to indicate if the Right mouse button is pressed when dragging
  //----------------------------------------------------------------------------------------------------------------------
  bool m_translate;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_origX;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value
  //----------------------------------------------------------------------------------------------------------------------
  int m_origY;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous x mouse value for Position changes
  //----------------------------------------------------------------------------------------------------------------------
  int m_origXPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the previous y mouse value for Position changes
  //----------------------------------------------------------------------------------------------------------------------
  int m_origYPos;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief the model position for mouse movement
  //----------------------------------------------------------------------------------------------------------------------
  ngl::Vec3 m_modelPos;
  /// @brief Our Camera
  ngl::Camera *m_cam;
  /// @brief our transform stack for drawing the teapots
  ngl::TransformStack m_transformStack;
    void loadTexture();


    //----------------------------------------------------------------------------------------------------------------------
    /// @brief current zoom
    //----------------------------------------------------------------------------------------------------------------------
    double m_zoom;

    ngl::Material m_material;

    Texture m_texture;

    /// 1 for texture and 0 for phong
    bool m_shaderMode;

    GLuint m_currentTextureName;


protected:

  /// @brief  The following methods must be implimented in the sub class
  /// this is called when the window is created
  void initializeGL();

  /// @brief this is called whenever the window is re-sized
  /// @param[in] _w the width of the resized window
  /// @param[in] _h the height of the resized window
  /// @note these are part of the Qt API so can't be changed to the coding standard
  /// so it can't be called resizeGL )
  void resizeGL(
                const int _w,
                const int _h
               );
  /// @brief this is the main gl drawing routine which is called whenever the window needs to
  /// be re-drawn
  void paintGL();

private :

        ngl::VertexArrayObject *m_vaoSphere;

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (
                          QMouseEvent * _event
                        );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mousePressEvent (
                            QMouseEvent *_event
                         );

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent (
                            QMouseEvent *_event
                            );

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void wheelEvent(
                      QWheelEvent *_event
                   );


};

#endif
