import QtQuick 2.12
import QtGraphicalEffects 1.0

Rectangle {
    color: "black"
	Image {
		id: field
		anchors.fill: parent
		anchors.centerIn: parent
		fillMode: Image.PreserveAspectFit
		source: "images/field.png"
	}
	ColorOverlay {
		anchors.fill: field
		source: field
		color: pdc.ambient
	}
	Image {
		anchors.fill: parent
		fillMode: Image.PreserveAspectFit
		source: "images/car-highlights.png"
	}
	Item {
		id: detectArea
		anchors.fill: parent
		scale: 0.5

		Image {
			id: detectFront
			source: "images/front-area.png"
			x: -17
			y: 230
		}
		
		Image {
			id: detectRear
			source: "images/rear-area.png"
			x: -60
			y: 407
		}

		ColorOverlay {
			anchors.fill: detectFront
			source: detectFront
			color: "#FFF000"
		}

		ColorOverlay {
			anchors.fill: detectRear
			source: detectRear
			color: "#FFF000"
		}
	}
}
