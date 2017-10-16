grammar textworld;

world: WORLD ID LCB
	worldnode*
	connection*
		RCB;

worldnode: WORLDNODE ID LCB 
	assignment*
	object*
		RCB;
		
object: OBJECT ID LCB
	assignment*
	subobject*
		RCB;
		
subobject: SUBOBJECT ID LCB
	assignment*
		RCB;
	
connection: CONNECTION ID LCB
	assignment*
		RCB;
		
assignment: ID EQ value SC;

value: STRING | INT;

WORLD : 'world';
WORLDNODE : 'worldnode';
OBJECT : 'object';
SUBOBJECT : 'subobject';
CONNECTION : 'connection';
LCB: '{';
RCB: '}';
EQ: '=';
SC: ';';
ID : [a-zA-Z][a-zA-Z0-9_]* ;  
STRING: '"' ~('"')* '"';
INT: [+-]?[0-9]+;       
WS : [ \t\r\n]+ -> skip ;