package pong;

import java.awt.Color;
import java.awt.Graphics;
//import java.awt.Rectangle;
import java.util.Random;

public class Ball extends Entity{
	
	//Direction
	private double dx, dy;
	
	public Ball() {
	    speed = 1.5 + (Game.dificuldade/2);
		width = 6;
		height = 6;
		x = Game.WIDTH/2 - width;
		y = Game.HEIGHT/2 - height;
		
		int angle = new Random().nextInt(360);
		dx = Math.cos(Math.toRadians(angle));
		dy = Math.sin(Math.toRadians(angle));
	}
	
    public void wallCollision(){
		/*Colisões com paredes*/
		//Impede que saia da tela
		if (y > Game.HEIGHT-height){
            dy*=-1;
            y = Game.HEIGHT-height;
        }else if(y < 0){ 
            dy *= -1; 
            y = 0;
        }
		
		if (x < 0) {
			//System.out.println("Ponto do inimigo!");
			Enemy.score++;
			x = 0;
            dx *= -1;
		}
		if (x > Game.WIDTH-width) {
			//System.out.println("Ponto do jogador!");
			Player.score++;
            x = Game.WIDTH-width;
			dx *= -1;
		}
    }

    public void entityCollision(Entity entity){

        if( x < entity.getX() + entity.getWidth()
            && x + width > entity.getX()
            && y < entity.getY() + entity.getHeight()
            && y + height > entity.getY()){
            if(Math.abs((x+(double)width/2) - (entity.getX() + (double)entity.getWidth()/2)) > ((double)width/2 + (double)entity.getWidth()/2)/2){
                dx *= -1;
                if(x+(double)width/2 > entity.getX() + (double)entity.getWidth()/2)x = entity.getX() + entity.getWidth();
                else x = entity.getX() - width;
                dy += ((y + (double)height/2) - (entity.getY() + (double)entity.getHeight()/2))/((double)entity.getHeight()/2 + (double)height/2);
                fixSpeed();
            }else{
                if(y+(double)height/2 > entity.getY() + (double)entity.getHeight()/2)y = entity.getY() + entity.getHeight();
                else y = entity.getY() - height;
                dy *= -1;
            }
        }
    }
	public void tick(){
		wallCollision();
	    entityCollision(Game.player);
        entityCollision(Game.enemy);

        ///*Colisões com raquetes*/
		//Rectangle bounds = new Rectangle((int)(x+(dx*speed)), (int)(y+(dy*speed)), width, height);
		//Rectangle boundsPlayer = new Rectangle ((int)Game.player.getX(), (int)Game.player.getY(),
		//		Game.player.getWidth(), Game.player.getHeight());
		//Rectangle boundsEnemy = new Rectangle ((int)Game.enemy.getX(), (int)Game.enemy.getY(),
		//		Game.enemy.getWidth(), Game.enemy.getHeight());
		//
		//if (bounds.intersects(boundsPlayer)) {
		//	dx *= -1;			
		//	if ( (x + width/2) - ( Game.player.getX() + Game.player.getWidth()/2 ) <
		//			(width/2 + Game.player.getWidth()/2) ) {
		//		x = Game.player.getX() + Game.player.getWidth();
		//	}else {
		//		double centroBall = y + height/2;
		//		double centroPlayer = Game.player.getY() + Game.player.getHeight()/2;
		//		
		//		// 0~100% de força (centro da bola - centro da raquete) / centro da raquete
		//		//Negativo = inclina pra cima, positivo = inclina pra baixo
		//		double kickStrength = (centroBall - centroPlayer) / (Game.player.getHeight()/2);
		//		dy += (speed*kickStrength);
		//	}
		//	
		//}
		//if (bounds.intersects(boundsEnemy)) { 
		//	dx *= -1;
		//	if ( ( Game.enemy.getX() + Game.enemy.getWidth()/2 ) - (x + width/2) <
		//			(width/2 + Game.enemy.getWidth()/2) ) {
		//		dy*= -1;
		//		x = Game.enemy.getX() - width;
		//	}else {
		//		double centroBall = y + height/2;
		//		double centroEnemy = Game.enemy.getY() + Game.enemy.getHeight()/2;
		//		
		//		// 0~100% de força (centro da bola - centro da raquete) / centro da raquete
		//		//Negativo = inclina pra cima, positivo = inclina pra baixo
		//		double kickStrength = (centroBall - centroEnemy) / (Game.enemy.getHeight()/2);
		//		dy += (speed*kickStrength);
		//	}
		//}
		
		//Movimento: direction * speed
		fixSpeed();
		x += dx*speed;
		y += dy*speed;	
	}
	
	public void fixSpeed() {
		//Modulo = tamanho do vetor
		double mod = dx*dx + dy*dy;
		mod = Math.sqrt(mod);
		dx /= mod;
		dy /= mod;
		
		//Regular angulo minimo/maximo
		double maxAngle = Math.PI/4; //radianos
		double angle = Math.atan(dy/dx); //radianos
		if (Math.abs(angle) > maxAngle) {
			dx = Math.signum(dx) * Math.cos(maxAngle);
			dy = Math.signum(dy) * Math.sin(maxAngle);
		} 	
	}

	public void render(Graphics g) {
		g.setColor(Color.YELLOW);
		g.fillRect((int) x, (int) y, width, height);
	}

	public double getDx() {
		return dx;
	}

	public double getDy() {
		return dy;
	}
}
