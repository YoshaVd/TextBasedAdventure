world world1 {
	worldnode camp {
		name = "camp";
		description = "An abandoned shelter amidst the woods.";
		object fire{}
		object branches {
			name = "branches";
			worldDescription = "Some dry branches lie in the far left corner of the room.";
			info = "These could provide some fuel for a fire.";
			useText = "You throw the branches on the campfire and blow the coals, they catch fire almost immediately.";
			takeText = "You pick up the branches";
			wood = 25;
			pickup = 1;
			usability = "destroyAfterUse";
			element = "fire";
		}
	}
	
	worldnode riverbank1 {
		name="riverbank1";
		description="A field of tall grass bordering a small stream in the east.";
		object stream {
			name = "stream";
			worldDescription = "The stream flows rapidly by the edge of the grassland.";
			info = "The water looks clear, it's probably drinkable.";
			useText = "The water is ice cold but tastes well enough.";
			usability = "unlimited";
			drink = 60;
		}
	}
	
	worldnode riverbank2 {
		name = "riverbank2";
		description = "A hillside of tall grass, to the east lies a river.";
		object rocks {
			name = "rocks";
			worldDescription = "A set of large rocks sits higher up the hill.";
			info = "Looking at rocks won't get you anywhere, or will it? You spot an axe leaning on one of them.";
		}
		object axe {
			name = "axe";
			worldDescription = "";
			info = "It's a bit rusty but feels sharp enough still.";
			takeText = "You pick up the old axe and give it a swing, feels solid enough.";
			usability = "unlimited";
			command = "chop";
			command = "swing";
			command = "cleave";
			pickup = 1;
		}
		
	}
	
	worldnode forest1 {
		name = "forest1";
		description = "An old forest with tall trees and dense foliage.";
		object trees {
			name = "trees";
			worldDescription = "";
			info = "These trees are old and massive, not likely to yield fuel for the fire easily.";
		}
		object brambles {
			name = "brambles";
			worldDescription = "There's brambles ranging from the south to the northwest.";
			info = "Looks like they might be carrying ripe blackberries.";
		}
		object berries {
			name = "blackberries";
			worldDescription = "";
			info = "These berries look ripe and untouched.";
			takeText = "You pick a handful of berries.";
			useText = "The berries are revitalizing and taste sweet.";
			food = 20;
			pickup = 1;
			usability = "destroyAfterUse";
		}
	}
	
	worldnode forest2 {
		name = "forest2";
		description = "A small open space in the forest surrounded by tall oak trees.";
		object willow {
			name = "willow";
			worldDescription = "In the center of the open space stands a lone willow tree.";
			info = "An ancient willow covered in moss.";
		}
		object birch {
			name = "birch";
			worldDescription = "To the north lies a pond with a young birch tree at the edge.";
			worldDescriptionUsed = "To the north lies a pond with a stump of a young birch next to it.";
			info = "This tree looks like it could be easily cut down with the right tool.";
			infoUsed = "A small stump, looks like it was cut recently.";
			useText = "The tree goes down handily, you chop it into smaller pieces.";
			usability = "once";
			tool = "axe";
			subobject logs {
				name = "logs";
				info = "These will provide good fuel for the fire.";
				worldDescription = "An armful of birch logs are neatly stacked next to a tree stump";
				takeText = "You lift the logs from the ground in a neat bundle.";
				useText = "You throw the logs on the fire, causing embers to fly up.";
				usability = "destroyAfterUse";
				element = "fire";
				pickup = 1;
			 }
		}
	}

	worldnode rockCoast {
		name = "rockCoast";
		description = "A rocky piece of land stretched alongside the stream.";
		object stream {
			name = "stream";
			worldDescription = "";
			info = "The stream can't be reached from the higher rock formation you're on, maybe it's accessible downstream.";
		}
		object rocks {
			name = "rocks";
			worldDescription = "";
			info = "They're rocks... what did you expect?";
		}
		object bush {
			name = "bush";
			worldDescription = "There's a large boulder surrounded by a bush to the west.";
			info = "Upon closer inspection the bush appears to contain an old tattered backpack.";
		}
		object backpack {
			name = "backpack";
			info = "It looks worn but seems strong enough to carry some things around with.";
			worldDescription = "";
			pickup = 1;
			takeText = "You pick up the backpack.";
			useText = "You swing the backpack over your shoulder.";
			usability = "destroyAfterUse";
			inventoryCapacity = 3;
		}
	}
	
	connection campRiver{
		target = "riverbank1";
		direction = "east";
		start = "camp";
	}
	connection riverCamp{
		target = "camp";
		direction = "west";
		start = "riverbank1";
	}
	connection river1River2{
		target = "riverbank2";
		direction = "north";
		start = "riverbank1";
	}
	connection river2River1{
		target = "riverbank1";
		direction = "south";
		start = "riverbank2";
	}
	connection campForest1{
		target = "forest1";
		direction = "west";
		start = "camp";
	}
	connection forest1Camp{
		target = "camp";
		direction = "east";
		start = "forest1";
	}
	connection forest1Forest2{
		target = "forest2";
		direction = "north";
		start = "forest1";
	}
	connection forest2Forest1{
		target = "forest1";
		direction = "south";
		start = "forest2";
	}
	connection river1Rock{
		target = "rockCoast";
		direction = "south";
		start = "riverbank1";
	}
	connection rockRiver1{
		target = "riverbank1";
		direction = "north";
		start = "rockCoast";
	}
}