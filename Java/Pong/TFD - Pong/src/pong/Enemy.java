package pong;

import java.awt.Color;
import java.awt.Graphics;

public class Enemy extends Entity {
	
	public static int score = 0;
	public Enemy() {
		if(Game.dificuldade>=1){
            speed = 0.1+(Game.dificuldade/5);
        }else{
            speed = 0.25 + (Game.dificuldade/3);
        }
        width = 5;
		height = 30;
		x = Game.WIDTH - width;
		y = (Game.HEIGHT/2) - (height/2);
	}
	

	public void tick(){
        if(Game.dificuldade >= 1){
            opFollowBall();
        }else{
            
            followBall();
        }
    }
	
	public void followBall(){
		double centroBall = Game.ball.getY() + Game.ball.getHeight()/2;
		double centroEnemy = y + height/2;
		
		if (centroBall > centroEnemy) y+=speed;
		if (centroBall < centroEnemy) y-=speed;
		
		//y += (Game.ball.getY() - y - height/2) * dificuldade/10;

		if (y+height > Game.HEIGHT) y = Game.HEIGHT - height;
		if (y < 0) y = 0;
	}

    public void opFollowBall(){
        double endy = 0;
        double vx = Game.ball.getDx()*Game.ball.speed;
        double vy = Game.ball.getDy()*Game.ball.speed;
        double px = Game.ball.getX();
        double myx = 0;
        if(px < x){
            myx = x;
            px += Game.ball.getWidth();
        }
        if(px > x){
            myx = x+(double)width;
            px += 0;
        }
        double py = Game.ball.getY();
        double virtualHeight = (double)Game.HEIGHT - (double)Game.ball.getHeight();
        if(vx == 0)endy = py;
        else{
            double m = vy/vx;
            double b = py - m * px;
            endy = m*myx+b;
        }

        while(endy > 2*virtualHeight)endy = endy - 2*virtualHeight;
        while(endy < -virtualHeight)endy = endy + 2*virtualHeight;
        if(endy > virtualHeight)endy = virtualHeight - (endy - virtualHeight);
        if(endy < 0)endy = virtualHeight - (virtualHeight + endy);
        
        endy+=((double)Game.ball.getHeight())/2;
        double targetOffset = 0;
        if(endy + targetOffset> (double)y+((double)height)/2 + speed){
            y+=speed;
        }else if(endy + targetOffset < (double)y+((double)height)/2-speed){
            y-=speed;
        }
		
        if (y+height > Game.HEIGHT) y = Game.HEIGHT - height;
		if (y < 0) y = 0;
    }

	public void render(Graphics g) {
		g.setColor(Color.RED);
		g.fillRect((int) x, (int) y, width, height);
	}
}
