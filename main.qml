import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 6.5
import "."
import QtQuick.Window
import MyApp.HandleUser
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
                    property int validfirstname: 0
                    onTextChanged:
                    {
                        if(firstname.length<3)
                        {
                            errortext.visible = true
                            errortext.text = "at least 3 character"
                            firstname.validfirstname= 0
                        }
                        else
                        {
                            errortext.visible = false
                            firstname.validfirstname= 1
                        }
                    }
                }
                Text {
                    id: errortext
                    color:"red"
                    visible: false
                    font.pixelSize: 12
                    anchors.margins: 2
                }
                TextField
                {
                    id:lastname
                    placeholderText: "lastname"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validlastname: 0
                    onTextChanged:
                    {
                        if(lastname.length<3)
                        {
                            errortext2.visible = true
                            errortext2.text = "at least 3 character"
                            lastname.validlastname= 0
                        }
                        else
                        {
                            errortext2.visible = false
                            lastname.validlastname= 1
                        }
                    }
                }
                Dialog
                {
                    id:message
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
                Text {
                    id: errortext2
                    color:"red"
                    visible: false
                    font.pixelSize: 12
                    anchors.margins: 2
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
                        if(phonefield.length!==11 || phonefield.text[0]!==0 || phonefield.text[1]!==9)
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
                TextField
                {
                    id:datefield
                    placeholderText: "date"
                    width: insiderect.width-30
                    font.pixelSize: 14
                    property int validdate: 0
                    onTextChanged:
                    {
                        if(datefield.length!==10)
                        {
                            dateerror.visible = true
                            dateerror.text = "invalid date format"
                        }
                        else
                        {
                        var flag=1;
                        for (var i=0;i<=9;i++)
                            {
                                if(i===4 || i===7)
                                {
                                    if(datefield.text[i]!=='/')
                                    {
                                      flag=0
                                      break
                                    }
                                }
                                else
                                {
                                if (!(datefield.text[i]>='0' && datefield.text[i]<='9'))
                                {
                                   flag=0
                                   break
                                }
                                }
                            }
                        if(flag===0)
                        {
                            dateerror.visible = true
                            dateerror.text = "invalid date format"
                            datefield.validdate = 0
                        }
                        else
                        {
                            dateerror.visible = false
                            datefield.validdate = 1
                        }
                        }
                    }
                }
                ComboBox
                {
                    id:sessions
                    model: ["8 sessions" ,"12 sessions"]
                    width: datefield.width

                }
                Text {
                    id: dateerror
                    color:"red"
                    visible: false
                    font.pixelSize: 12
                    anchors.margins: 2
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
                            if(firstname.validfirstname && lastname.validlastname && datefield.validdate && phonefield.validphonenum)
                            {
                            HandleUser.addUser(firstname.text ,lastname.text ,phonefield.text , datefield.text ,sessions.currentIndex)
                            console.log(userfunc.getfirstname())
                            message.open()
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
