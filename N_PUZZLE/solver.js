var final_solution = snail_solution(new Board(3, 3));
var random_board = snail_solution(new Board(3, 3));
//var tree_graph = new Node(random_board, null);
var	depth = 0;
//closed_set.add(random_board.pieces.toString());
function compute_solution(board)
{
	var		pm;
	var		temp_board;
	var		t;
	var		depth;
	//var		i;
//	var		depth;
//	var		og_board;

	//depth = 0;
	//og_board = board;
	var open = new Set();
	var open_sorted = [];
	var closed_set = new Set();
	open.add(board.toString());
	board.cost = Manhattan_distance(board);
	open_sorted.push(board);
	board.parent = null;
	depth = 1;
	while (true)
	{
		t = board;
		board = open_sorted[0];
		//print_board(board);
		open_sorted.splice(0, 1);
		closed_set.add(board.pieces.toString());
		if (!closed_set.has(t.pieces.toString()))
			board.child = t;
		if (board.pieces.toString() == final_solution.pieces.toString())
		{
			return board;
		}
		pm = possible_moves(board);
		for (var i = 0; i < pm.length; i++)
		{
			temp_board = duplicate_board(board);
			do_move(temp_board, pm[i]);
			console.log("Possible moves = " + pm);
			if (!closed_set.has(temp_board.pieces.toString()) && !open.has(temp_board.pieces.toString()))
			{
						console.log("Going " + pm[i]);
				print_board(temp_board);
				open.add(temp_board.pieces.toString());
				temp_board.cost = Manhattan_distance(board);
				console.log("Cost is = " + temp_board.cost);
				temp_board.parent = board;
				var j = 0;
						console.log("Open_sorted size = " + open_sorted.length)
				if (open_sorted.length)
				{
					//console.log(open_sorted[j].cost + " > " + temp_board.cost);
					while (open_sorted[j].cost > temp_board.cost && j > open_sorted.length)
					{
						//console.log("j = " + j);
						j++;
					}
					j = 0;
					var os = "  Open_sorted: ";
					while (j < open_sorted.length)
					{
						os += open_sorted[j].cost + ", ";
						j++;
					}
					console.log(os);
				}
				open_sorted.splice(j, 0, temp_board);
				//console.log(open_sorted[0].pieces.toString() + " vs " + final_solution.pieces.toString());
				//return ;
				//console.log("done");
				if (open_sorted[0].pieces.toString() == final_solution.pieces.toString())
				{
					console.log("solved");
					return (temp_board);
				}
			}
		}
		depth++;
		if (depth == 3)
			break	;
	}
}

function		print_path(board)
{
	var			temp;
	var			t;

	temp = board;
	while (temp.parent)
	{
		t = temp;
		//print_board(temp);
		temp = temp.parent;
		temp.child = t;
	}
	while (temp.pieces.toString() != final_solution.pieces.toString())
	{
		print_board(temp);
		temp = temp.child;
	}
	print_board(temp);
}

function Board(width, height) {
	this.width = width;
	this.height = height;
	this.pieces = new Array(height);
	for (var row = 0; row < height; row++) {
		this.pieces[row] = new Array(width);
	}
}

function snail_solution(board) {
	var top_piece = board.width * board.height - 1;
	var x = 0;
	var y = 0;
	var shrink = 1;
	for (var piece = 0; piece < top_piece;) {
		while (x < board.width - shrink) {
			piece++;
			board.pieces[y][x] = piece;
			x++;
		}
		while (y < board.height - shrink) {
			piece++;
			board.pieces[y][x] = piece;
			y++;
		}
		while (x > shrink - 1) {
			piece++;
			board.pieces[y][x] = piece;
			x--;
		}
		shrink++;
		while (y > shrink - 1) {
			piece++;
			board.pieces[y][x] = piece;
			y--;
		}
	}
	//x++;
	//board.pieces[y][x] = 0;
	return (board);
}

function find_empty(board) {
	for (var y = 0; y < board.height; y++){
		for (var x = 0; x < board.width; x++){
			if (!board.pieces[y][x])
				return [x, y];
		}
	}
}

function possible_moves(board) {
	var empty_pos = find_empty(board);
	var moves = "";

	if (empty_pos[1] < board.height - 1) {
		moves += "n";
	}
	if (empty_pos[1] > 0) {
		moves += "s";
	}
	if (empty_pos[0] > 0) {
		moves += "e";
	}
	if (empty_pos[0] < board.width - 1) {
		moves += "w";
	}
	return moves;
}

function print_possible_moves()
{
	var moves = possible_moves(board);
	document.getElementById("outp").innerHTML += moves + "<br>";
}

function print_board(board){
	var y = 0;
	var row;
	console.log("---");
	while (y < board.height)
	{
		x = 0;
		row = "";
		while (x < board.width)
		{
			if (board.pieces[y][x])
			{
				row += board.pieces[y][x];
				row += " ";
			}
			else {
				row += "0";
				row += " ";
			}
			x++;
		}
		document.getElementById("outp").innerHTML += row + "<br>";
		console.log(row);
		y++;
	}
	document.getElementById("outp").innerHTML += "<br>";
}

function do_move(board, move)
{
	var empty = find_empty(board);
	var x = empty[0];
	var y = empty[1];
	var x2 = x;
	var y2 = y;
	var temp;
	if (move == "n" && y + 1 < board.height)
	{
		y2 += 1;
	}
	else if (move == "e")
	{
		x2 -= 1;
	}
	else if (move == "s" && y > 0)
	{
		y2 -= 1;
	}
	else if (move == "w")
	{
		//temp.pieces[y][x] = board.pieces[y][x + 1];
		//temp.pieces[y][x + 1] = null;
		x2 += 1;
	}
	temp = board.pieces[y2][x2];
	board.pieces[y2][x2] = board.pieces[y][x];
	board.pieces[y][x] = temp;
//	print_board(random_board)
}

function clear_html()
{
	document.getElementById("outp").innerHTML = "";
}

function Node(board, children, depth)
{
	this.board = board;
	this.children = children;
	this.depth = depth;
}

Node.prototype.add_child = function(board){
	this.children.push(board);
};

function	randomize_board(board, sequence)
{
	var		i;

	i = 0;
	while (i < sequence.length)
	{
		do_move(board, sequence[i]);
		i++;
	}
	clear_html();
	print_board(board);
}
function	calculate_tile(board, value)
{
	var		x1;
	var		y1;
	var		x2;
	var		y2;

	y1 = 0;
	y2 = 0;
	//clear_html();
	//print_board(board);
	//print_board(final_solution);
	while (y1 < board.height)
	{
		x1 = 0;
		while (x1 < board.width)
		{
				if (board.pieces[y1][x1] == value)
				{
					//document.getElementById("outp").innerHTML += "RandomBoard:      y1=" + y1 + "        x1=" + x1 + "<br>";
					break	;
				}
				x1++;
		}
		if (board.pieces[y1][x1] == value)
			break	;
		y1++;
	}
	while (y2 < final_solution.height)
	{
		//document.getElementById("outp").innerHTML += "AWE!<br>";
		x2 = 0;
		while (x2 < final_solution.width)
		{
			//if (final_solution.pieces[y2][x2])
				if (final_solution.pieces[y2][x2] == value)
				{
					//document.getElementById("outp").innerHTML += "AWE!<br>";
					//document.getElementById("outp").innerHTML += "RandomBoard:      y2=" + y2 + "        x2=" + x2 + "<br>";
					break	;
				}
			x2++;
		}
		if (final_solution.pieces[y2][x2] == value)
		{
				break	;
				//document.getElementById("outp").innerHTML += "here";
		}
		y2++;
	}
	//document.getElementById("outp").innerHTML += y2 + "<br>";
	//document.getElementById("outp").innerHTML += "(" + x1 + "-" + x2 + ")" + "+ (" + y1 + "-" + y2 + ")" + "<br>";
	return Math.abs((x1 - x2) + (y1 - y2));
}

function	Manhattan_distance(board)
{
	var		y;
	var		x;
	var		total;

	y = 0;
	total = 0;
	while (y < board.height)
	{
		x = 0;
		//document.getElementById("outp").innerHTML += "here";
		while (x < board.width)
		{
			if (board.pieces[y][x])
				total += calculate_tile(board, board.pieces[y][x]);
			//document.getElementById("outp").innerHTML += total;
			x++;
		}
		//document.getElementById("outp").innerHTML += "<br>";
		y++;
	}
	//document.getElementById("outp").innerHTML += "AWE!<br>";
	return (total);
}

function	duplicate_board(board)
{
	var		x;
	var		y;
	var		new_board;

	y = 0;
	new_board = new Board(board.width, board.height);
	while (y < new_board.height)
	{
		x = 0;
		while (x < new_board.width)
		{
			new_board.pieces[y][x] = board.pieces[y][x];
			x++;
		}
		y++;
	}
	return (new_board);
}
