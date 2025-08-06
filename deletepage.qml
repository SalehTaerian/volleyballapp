import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import "."
import QtQuick.Window
import MyApp.HandleUser
// import MyApp.infopage
Window{
    id: win
    width:screen.width
    height:screen.height
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
                    text: "delete page"
                    font.pixelSize: 26
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    color:"#468898"
                }
                TextField
                {
                    id:phonefield
                    placeholderText: "phonenumber"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    echoMode: TextInput.Password
                    property int validphonenum: 0
                    onTextChanged:
                    {
                        if(phonefield.text.length!==11 || phonefield.text[0]!=='0' || phonefield.text[1]!=='9')
                        {
                            phoneerror.visible = true
                            phoneerror.text = "invalid phone number format"
                            phonefield.validphonenum = 0
                        }
                        else
                        {
                            phoneerror.visible = false
                            phonefield.validphonenum = 1
                        }
                    }
                }
                Text {
                    id: phoneerror
                    color:"red"
                    visible: false
                    font.pixelSize: 12
                    anchors.margins: 2
                }
                Dialog
                {
                    id:okmessage
                    title: "adding was successful ✔"
                    standardButtons: Dialog.Ok
                    // background:Rectangle
                    // {
                    //     color:"#c5e1a5"
                    //     anchors.fill:message
                    //     radius:10
                    // }
                    height: mainrect.height/4
                    width:mainrect.width/4
                    anchors.centerIn: parent
                    visible: false
                    contentItem: Label
                    {
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                Dialog
                {
                    id:ermessage
                    title: "adding was'nt successful ❌"
                    standardButtons: Dialog.Ok
                    // background:Rectangle
                    // {
                    //     color:"#c5e1a5"
                    //     anchors.fill:message
                    //     radius:10
                    // }
                    height: mainrect.height/4
                    width:mainrect.width/4
                    anchors.centerIn: parent
                    visible: false
                    contentItem: Label
                    {
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                }
                Row{
                    spacing:7
                    anchors.horizontalCenter: parent.horizontalCenter
                    width:info.width + submit.width + spacing
                    Button
                    {
                        id:info
                        text: "back"
                        width: col.width/3
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
                    Button
                    {
                        id:submit
                        text: "submit"
                        width: col.width/3
                        onClicked:
                        {
                           var flag = HandleUser.deleteUser(phonefield.text)
                           if(flag)
                           {
                               okmessage.open()
                           }
                           else
                           {
                               ermessage.open()
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
