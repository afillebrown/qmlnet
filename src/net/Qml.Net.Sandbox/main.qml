import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import test 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
	Item {
		Timer {
			interval: 1000; running: true; repeat: true
			onTriggered: {
                Net.gcCollect(2)
                var collection = test.Contacts
                var contact = test.CreateContact(34, "werw")
                console.log(collection.Count)
                collection.Add(contact)
                console.log(collection.Count)
			}
		}
	}
    
	Image {
        source: "Images/placeholder.png"
    }

	TestQmlImport {
		id: test
	}
}
