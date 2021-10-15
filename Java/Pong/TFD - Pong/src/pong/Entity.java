package pong;

import java.awt.Graphics;

public abstract class Entity {
	protected int width;
	protected int height;
	protected double x, y;
	protected double speed;

	public abstract void tick();
	public abstract void render(Graphics g);
	
	public double getX() {
		return x;
	}

	public double getY() {
		return y;
	}
	
	public int getWidth() {
		return width;
	}
	
	public int getHeight() {
		return height;
	}

    public double getSpeed(){
        return speed;
    }
}
