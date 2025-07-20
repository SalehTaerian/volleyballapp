import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import "."
import QtQuick.Window
Window{
    id: win
    width:screen.width
    height:height.width
    minimumWidth: 320
    minimumHeight: 568
    title:"main page"
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
            contentHeight: col.height
            Column
            {
                id:col
                width: parent.width*0.9
                spacing: 18
                anchors.top:parent.top
                anchors.topMargin: 15
                anchors.left: parent.left
                anchors.leftMargin: 14

                Label
                {
                    width:parent.width
                    id:label1
                    text: "main page"
                    font.pixelSize: 26
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    color:"#468898"
                }
                TextField
                {
                    id:firstname
                    placeholderText: "firstname"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:lastname
                    placeholderText: "lastname"
                    width: insiderect.width-30
                    font.pixelSize: 14
                }
                TextField
                {
                    id:phonefield
                    placeholderText: "phonenumber"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                }
                Row{
                    spacing:7
                    anchors.horizontalCenter: parent.horizontalCenter
                    width:info.width + submit.width + spacing
                    Button
                    {
                        id:info
                        text: "info"
                        width: col.width/3
                        onClicked:
                        {
                            var component =Qt.createComponent("restaurantsignin.qml")
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
                        }                    }
                    Button
                    {
                        id:submit
                        text: "submit"
                        width: col.width/3
                        onClicked:
                        {
                            if(!db.usernameexist(usernamefield.text))
                            {
                                db.adduser(usernamefield.text , pass.text , namefield.text , resta.text , country.text , city.text , postalcode.text , homeadr.text ,homephone.text , bio.text);
                            }
                            else
                            {
                                // db.printAllUsers();
                            console.log("this username already exist")
                            }
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
