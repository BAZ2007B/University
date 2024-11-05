//Parameters
var figures = [
	["circle",50,50,10],
	["square",150,50,25],
	["ellipse",200,200,30,40]
];

const canvas = document.getElementById('canvas');
const context = canvas.getContext('2d');

//User's action feedback
canvas.onclick = function(event) {
	document.getElementById("audio").play();
	
	//Event handler to resize the canvas when the document view is changed
	window.addEventListener('resize', resizeCanvas, false);

	function resizeCanvas() {
		canvas.width = window.innerWidth;
		canvas.height = window.innerHeight;

		// Redraw everything after resizing the window
		drawing(); 
	}
	resizeCanvas();

	function drawing() {
		//Circle
		context.beginPath();
		context.arc(figures[0][1], figures[0][2], figures[0][3], 0, 2 * Math.PI, false);
		context.fillStyle = "gray";
		context.fill();
	
		//Square
		context.beginPath();
		context.rect(figures[1][1], figures[1][2], figures[1][3], figures[1][3]);
		context.fillStyle = "gray";
		context.fill();
	
		//Ellipse
		context.beginPath();
		context.ellipse(figures[2][1], figures[2][2], figures[2][3], figures[2][4], 0, 0, 2 * Math.PI);
		context.fillStyle = "black";
		context.fill();
	
		//Bezier curve
		/* Start a new Path */

		context.beginPath();
		context.lineWidth = 3;

		/* Curve 1: Upper half of the "S" shape */
		context.moveTo(50, 100);
		context.bezierCurveTo(50, 60, 120, 60, 120, 100);

		/* Curve 2: Lower half of the "S" shape */
		context.moveTo(50, 100);
		context.bezierCurveTo(50, 140, 120, 140, 120, 180);

		context.stroke();

		//Setup for animation
		var x = 0;
		var y = canvas.height-200;
	
		context.beginPath();
		context.rect(x, y, canvas.width, canvas.height);
		context.fillStyle = "black";
		context.fill();
	}

//Animation
	var flag = 0;
	function animation() {
		context.font = "10em Times";
		context.textAlign = "center";
		if (flag == 0) {
			context.fillStyle = "white";
			flag = 1;
		} else if (flag == 1) {
			context.fillStyle = "black";
			flag = 0;
		}
		context.fillText("Dead Memories", canvas.width/2, canvas.height);
		setTimeout(animation, 1000);
	}
	animation();
}