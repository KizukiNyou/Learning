package pong;

import java.awt.Color;
import java.awt.Graphics;

public class Player extends Entity {
	public static int score = 0;
	public boolean right, left;
	
	public Player() {
		speed = 1;
        width = 5;
		height = 30;
		x = 0;
		y = (Game.HEIGHT/2) - (height/2);
	}
	
	public void tick() {
		//Controle de direção
		if (right) y+=speed;
		if (left)  y-=speed;
		
		if (y+height > Game.HEIGHT) y = Game.HEIGHT - height;
		if (y < 0) y = 0;
	}
	
	public void render(Graphics g) {
		g.setColor(Color.BLUE);
		g.fillRect((int) x, (int) y, width, height);
	}
}
