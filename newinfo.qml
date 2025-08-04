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
                contentHeight: (HandleUser.getNumberOfUser()+1)*3 * 25
                Column
                {
                GridLayout {
                       id: table
                       columns: 3
                       anchors.fill: parent
                       columnSpacing: 3
                       rowSpacing: 5
                       anchors.margins: 5
                       Repeater {
                           model: (HandleUser.getNumberOfUser()+1)*3
                           anchors.margins: 5
                           delegate: Rectangle {
                               Layout.fillWidth: true
                               Layout.preferredHeight: 65
                               color: "lightblue"
                               border.color: "gray"
                               Label {
                                   anchors.centerIn: parent
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
                                       else
                                       {
                                           if(index%3===0)
                                           {
                                               return HandleUser.getUser((index-3)/3,0)
                                           }
                                           else if(index%3===1)
                                           {
                                               return HandleUser.getUser((index-3)/3,1)
                                           }
                                           else if(index%3===2)
                                           {
                                               return HandleUser.getUser((index-3)/3,2)
                                           }
                                       }
                                   }

                               }
                           }
                       }
                }
                Button
                {
                    id:back
                    text: "back"
                    width: col.width/2
                    anchors.centerIn: parent
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
                }
                ScrollBar.vertical: ScrollBar
                {
                    policy:ScrollBar.AsNeeded
                }
            }


            }

        }
    }
