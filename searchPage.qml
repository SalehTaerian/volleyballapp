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
    title:"search page"
    visible: true
    property int tableModelCount: 0
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
        Button{
        id:back
        anchors.top: whiterect.top
        anchors.left: whiterect.left
        icon.source: "qrc:/new/prefix1/left-arrow.png"
        width:parent.width/7
        height:parent.height/10
        background: null
        anchors.rightMargin: 0
        z:10
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
                    text: "search page"
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
                        tableModelCount = HandleUser.searchUser(firstname.text , lastname.text)
                        if(tableModelCount!==-1)
                        {
                            table.visible= true
                        }
                        else
                        {
                            table.visible= false
                        }
                        var foundUserIndex = HandleUser.searchUser(firstname.text , lastname.text)
                        console.log(foundUserIndex)
                    }
                }
                Text {
                    id: errortext2
                    color:"red"
                    visible: false
                    font.pixelSize: 12
                    anchors.margins: 2
                    }
                GridLayout {
                       id: table
                       columns: 5
                       anchors.fill: parent
                       columnSpacing: 3
                       rowSpacing: 5
                       anchors.margins: 5
                       anchors.topMargin: 60 + 2.5 * firstname.height
                       visible: false
                       Repeater {
                           model: 10
                           anchors.margins: 5
                           delegate: Rectangle {
                               Layout.fillWidth: true
                               Layout.preferredHeight: 65
                               color:
                               {
                                   if(index===0 || index===1 || index===2 || index===3 || index===4)
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
                                   font.pixelSize: whiterect.width*0.022
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
                                           return "registraion date"
                                       }
                                       else if(index===3)
                                       {
                                           return "Shahrieh time"
                                       }
                                       else if(index===4)
                                       {
                                           return "days"
                                       }
                                       else
                                       {
                                           var foundUserIndex = HandleUser.searchUser(firstname.text , lastname.text)
                                           console.log(foundUserIndex)
                                           if(foundUserIndex!==-1)
                                           {
                                           if(index%5===0)
                                           {
                                               return HandleUser.getUser((index+foundUserIndex*5-5)/5,0)
                                           }
                                           else if(index%5===1)
                                           {
                                               return HandleUser.getUser((index+foundUserIndex*5-5)/5,1)
                                           }
                                           else if(index%5===2)
                                           {
                                               return HandleUser.getUser((index+foundUserIndex*5-5)/5,2)
                                           }
                                           else if(index%5===3)
                                           {
                                               return HandleUser.getUser((index+foundUserIndex*5-5)/5,3)
                                           }
                                           else if(index%5===4)
                                           {
                                               return HandleUser.getUser((index+foundUserIndex*5-5)/5,4)
                                           }
                                           }
                                       }
                                   }

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
