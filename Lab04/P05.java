import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class P05 extends JFrame {
    String title = "Graphics Template";
    Color background = Color.BLACK;

    // 4**N exponential growth
    
    final int N = 6;
    
    void draw(Graphics g) {
        int w = getWidth();
        int h = getHeight();
        int r = Math.min(w, h) / 4;
        int x = w / 2;
        int y = h / 2;
        int c = 255;
        
        drawRect(g, x, y, r, c);
    }
    
    void drawRect(Graphics g, int x, int y, int r, int c) {
        if (c <= 0) {
            return;
        }
        
        int x1 = x - r;
        int y1 = y - r;
        int x2 = x + r;
        int y2 = y - r;
        int x3 = x + r;
        int y3 = y + r;
        int x4 = x - r;
        int y4 = y + r;
        
        drawRect(g, x1, y1, r / 2, c - 255 / N);
        drawRect(g, x2, y2, r / 2, c - 255 / N);
        drawRect(g, x3, y3, r / 2, c - 255 / N);
        drawRect(g, x4, y4, r / 2, c - 255 / N);
        
        g.setColor(new Color(c, 0, 0));
        g.fillRect(x1, y1, 2 * r, 2 * r);
    }
    

    public P05() {
        setTitle(title);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        DrawPanel panel = new DrawPanel();

        panel.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                System.exit(0);
            }
        });

        add(panel);


        setUndecorated(true);
        setExtendedState(JFrame.MAXIMIZED_BOTH);
        setVisible(true);
    }

    public static void main(String[] args) {
        new P05();
    }

    class DrawPanel extends JPanel {
        public DrawPanel() {
            setBackground(background);
            setFocusable(true);
            requestFocusInWindow();
            setDoubleBuffered(true);
        }

        public void paintComponent(Graphics g) {
            super.paintComponent(g);
            draw(g);
        }
    }
}
