    import QtQuick 2.15
    import QtQuick.Controls 2.15
    import QtQuick.Layouts 6.5
    import "."
    import QtQuick.Window
    import MyApp.HandleUser
    Window{
        id: win
        width:screen.width
        height:screen.height
        minimumWidth: 320
        minimumHeight: 568
        title:"info page"
        visible: true
        Rectangle
        {
            id:mainrect
            anchors.fill: parent
            color:"#333"
            Image {
                id: mainimage
                source: "qrc:/new/prefix1/details-ball-sport.jpg"
                fillMode: Image.PreserveAspectCrop
                opacity: 0.5
                anchors.fill: parent
            }
            Rectangle
            {
            id:whiterect
            radius:15
            color:"#FFFAF7"
            anchors.centerIn: parent
            width:Math.min(win.width-90 , 500)
            height:Math.min(win.height-130 , 750)
            Flickable
            {
                id:insiderect
                clip:true
                anchors.fill: parent
                contentHeight: (HandleUser.getNumberOfUser()+1)*4 * 20
                GridLayout {
                       id: table
                       columns: 4
                       anchors.fill: parent
                       columnSpacing: 3
                       rowSpacing: 5
                       anchors.margins: 5
                       anchors.topMargin: 30
                       Repeater {
                           model: (HandleUser.getNumberOfUser())*4+4
                           anchors.margins: 5
                           delegate: Rectangle {
                               Layout.fillWidth: true
                               Layout.preferredHeight: 65
                               color:
                               {
                                   if(index===0 || index===1 || index===2 || index===3)
                                   {
                                       "#F5EE9D"
                                   }
                                   else
                                   {
                                       "lightblue"
                                   }
                               }

                               border.color: "gray"
                               Label {
                                   anchors.centerIn: parent
                                   font.pixelSize: whiterect.width*0.024
                                   font.bold: true
                                   text:
                                    {
                                       if(index===0)
                                       {
                                           return "firstname"
                                       }
                                       else if(index===1)
                                       {
                                           return "lastname"
                                       }
                                       else if(index===2)
                                       {
                                           return "Shahrieh time"
                                       }
                                       else if(index===3)
                                       {
                                           return "days"
                                       }
                                       else
                                       {
                                           if(index%4===0)
                                           {
                                               return HandleUser.getUser((index-4)/4,0)
                                           }
                                           else if(index%4===1)
                                           {
                                               return HandleUser.getUser((index-4)/4,1)
                                           }
                                           else if(index%4===2)
                                           {
                                               return HandleUser.getUser((index-4)/4,2)
                                           }
                                           else if(index%4===3)
                                           {
                                               return HandleUser.getUser((index-4)/4,3)
                                           }
                                       }
                                   }

                               }
                           }
                       }
                }
                Button{
                id:back
                anchors.top: win.top
                anchors.left: win.left
                icon.source: "qrc:/new/prefix1/left-arrow.png"
                width:parent.width/2.5
                height:parent.height/3.75
                background: null
                anchors.rightMargin: 0
                // Component.onCompleted:
                // {
                //     back.y= back.y-100
                //     back.x= back.x+1
                // }
                onClicked:
                {
                    console.log("clickeddd")
                    var component =Qt.createComponent("main.qml")
                    if(component.status===Component.Ready)
                    {
                        var newWin = component.createObject(null ,{
                        width =win.width,
                        height =win.height,
                        x:win.x,
                        y:win.y,
                        visibility:win.visibility
                                                            })
                        newWin.show();
                        win.close();
                    }
                }

                }
                ScrollBar.vertical: ScrollBar
                {
                    policy:ScrollBar.AsNeeded
                }
            }


            }

        }
    }
