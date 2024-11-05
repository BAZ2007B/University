/*----Part 1----*/
//Main task
/*function findResult(array) {
	let result = 0;
	for (let i = 0; i < 2; i++) {
		result += array[i].count * array[i].price;
	}
	console.log(result);
	return result;
}*/
//Additional task
function findResult(array) {
	let result = 0;
	array.forEach(element => result += element.count * element.price);
	console.log(result);
	return result;
}

let array = [
	{name: "apple", count: 5, price: 70},
	{name: "orange", count: 10, price: 90}
];

let result = findResult(array);
let bill = [
	{array},
	{result}
];
console.log(Date());
console.log(JSON.stringify(bill));

/*----Part 2----*/
function offHighlight() {
	document.querySelectorAll("button.numbers, p").forEach(
		element => element.style.color = "black"
	);
}

function firstTask() {
	offHighlight();
	
	let text = document.getElementById("text");
	let oldText = text.innerHTML;
	const listItems = document.getElementById("list").getElementsByTagName("li");
	let newText = "";
	for (let i = 0; i < listItems.length; i++) {
		newText += listItems[i].textContent + " ";
	}
	text.innerHTML = newText;
	setTimeout(function() {
		text.innerHTML = oldText;
	}, 3000);
}

function secondTask() {
	offHighlight();
	
	let numbers = document.querySelectorAll("button.numbers");
	let oldStyle = numbers.style;
	numbers.forEach(element => element.style = "color: transparent");
	setTimeout(function() {
		numbers.forEach(element => element.style = oldStyle);
	}, 3000);
}

function thirdTask() {
	offHighlight();
	
	let searchItem = prompt("Найти", "");
	
	if (searchItem != null) {	
		let listItems = document.getElementById("list").getElementsByTagName("li");
		for (let i = 0; i < listItems.length; i++) {
			let item = listItems[i].textContent.replace(/(\r\n|\n|\r|\t)/gm,"");
			if (item == searchItem && listItems[i].childNodes[0].tagName == "BUTTON") {
				listItems[i].querySelector("button.numbers").style.color = "#cf8d58";
			} else if (item == searchItem && listItems[i].childNodes[0].tagName == "P") {
				listItems[i].querySelector("p").style.color = "#cf8d58";
			}
		}
	}
}

/*---Not related to the task---*/
document.addEventListener('keyup', (event) => {
	let text = document.getElementById("text");
	if (event.key == "F12" && text.innerHTML == "НАЖМИ F12") {
		text.innerHTML = "НАЖАТО";
	} else if (event.key == "F12" && text.innerHTML == "НАЖАТО") {
		text.innerHTML = "НАЖМИ F12";
	}
}, false);
