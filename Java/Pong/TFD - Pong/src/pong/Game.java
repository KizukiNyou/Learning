package pong;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;

import javax.swing.JFrame;

public class Game extends Canvas implements Runnable, KeyListener {
	
	private static JFrame frame;
	public static final int WIDTH = 180;
	public static final int HEIGHT = 120;
	public static final int SCALE = 5;
	
	public static double dificuldade = 0; //Afeta a velocidade da bola e do inimigo
	
	public static Player player;
	public static Enemy enemy;
	public static Ball ball;
	
	private boolean isRunning;
	private Thread thread;
	public BufferedImage layer;
	
	private String score;
	
	public static void main(String[] args) {
		Game game = new Game();
		game.initFrame();
		game.start();
	}
	
	public Game() {
		//Specify the canvas size
		this.setPreferredSize(new Dimension(WIDTH*SCALE, HEIGHT*SCALE));
		this.addKeyListener(this);
		
		player = new Player(); 
		enemy = new Enemy();
		ball = new Ball();
		
		layer = new BufferedImage(WIDTH, HEIGHT, BufferedImage.TYPE_INT_RGB);
	}
	
	public void initFrame(){
		frame = new JFrame("Pong");		
		frame.add(this);		
		frame.setResizable(false);		
		frame.pack();		
		frame.setLocationRelativeTo(null);		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
		frame.setVisible(true);
	}
	
	public synchronized void start() {
		isRunning = true;
		thread = new Thread(this);
		thread.start();
	}
	
	public synchronized void stop() {
		isRunning = false;
		try {
			thread.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	public void tick() {
		player.tick();
		enemy.tick();
		ball.tick();
	}
	
	public void render () {
		BufferStrategy bs = this.getBufferStrategy();
		if (bs == null) {
			this.createBufferStrategy(3);
			return;
		}
		Graphics g = layer.getGraphics();
		
		//////////Renderização do jogo///////////////
		//Limpa a tela (desenha o fundo da tela)
		g.setColor(Color.BLACK);
		g.fillRect(0, 0, WIDTH, HEIGHT);
		
		//Score
		score = Player.score + " : " + Enemy.score;
		g.setFont(new Font("Arial", Font.BOLD, 16));
		g.setColor(Color.WHITE);
		g.drawString(score, WIDTH/2-15, HEIGHT-8);
		
		//Entities
		ball.render(g);
		player.render(g);
		enemy.render(g);
		
		////////////////////////////////////////////
		
		g.dispose();
		g = bs.getDrawGraphics();
		g.drawImage(layer, 0, 0, WIDTH*SCALE, HEIGHT*SCALE, null);
		bs.show();
	}
	
	@Override	
	public void run() {
		requestFocus();
		double amountOfTicks = 120.0; //Frames per second (fps)
		double ns = 1000000000 / amountOfTicks; //Time between each frame (in nanoseconds)
		double delta = 0;
		long lastTime = System.nanoTime();
		
		//Main loop
		while(isRunning) {
			long now = System.nanoTime();
			delta += (now - lastTime) / ns;
			lastTime = now;
			if (delta >= 1) {
				tick();
				render();
				delta--;
			}
		}		
		
		stop();	
	}

	@Override
	public void keyTyped(KeyEvent e) {}

	@Override
	public void keyPressed(KeyEvent e) {
		if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
			player.right = true;
		}
		else if (e.getKeyCode() == KeyEvent.VK_LEFT) {
			player.left = true;
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
			player.right = false;
		}
		else if (e.getKeyCode() == KeyEvent.VK_LEFT) {
			player.left = false;
		}
	}
}
