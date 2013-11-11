import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Layouts 1.0

ApplicationWindow {
	title: "Hello Network Client"
	visible: true
	width: 640
	height: 480

	// glue code between C++ and QML
	Component.onCompleted: {
		lineEntered.connect(client.sendLine)
		client.lineReceived.connect(appendOutput)
		client.error.connect(appendOutput)
	}



	/* slot called from the outside to append rich text to the output area */
	function appendOutput(message) {
		outputArea.append(message);
	}

	/* signal sent to the outside to handle user inputs */
	signal lineEntered(string line)

	/* slot getting called by the send button, or when the return key is pressed */
	function forwardLine() {
		var line = inputField.text
		if (line !== "") {
			inputField.text = ""
			line += "\n"
			lineEntered(line)
			appendOutput("Sent: " + line);
		}
	}

	ColumnLayout {
		anchors.fill: parent
		spacing: 6

		TextArea {
			id: outputArea
			textFormat: TextEdit.RichText
			font.family: "Monospace"
			Layout.fillHeight: true
			Layout.fillWidth: true
			readOnly: true

			text: "<b>Hello</b> <i>World!</i>"
		}

		RowLayout {
			spacing: 6

			TextField {
				id: inputField
				focus: true
				Layout.fillWidth: true
				onAccepted: forwardLine()
			}

			Button {
				text: "Send"
				onClicked: forwardLine()
			}
		}
	}

}
