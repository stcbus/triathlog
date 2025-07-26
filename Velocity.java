/**
Velocity.java, written by Curt Austin, 1996
Inspired by Ken Roberts C program BikePower
Version 1.0b4 
Public domain
*/

import java.awt.*;
import java.applet.*;
import java.lang.Math;

public class Velocity extends Applet {
	InputArea	in1, in2;

	public void init() {
	
		setLayout(new GridLayout(1,2,5,5));
		
		in1 = new InputArea();
		in2 = new InputArea();
		
		setBackground(Color.cyan);
		add(in1);
		add(in2);
	}
		
	public Insets insets() {
		return new Insets(6,6,6,6);
	}
	
	public void paint(Graphics g) {
		int w=this.size().width-1;
		int h=this.size().height-1;
		
		g.setColor(Color.red);
		g.drawRect(0, 0, w, h);
		g.drawLine(w/2, 0, w/2, h);
		return;
	}

    public boolean handleEvent(Event e) {
	if (e.id == Event.WINDOW_DESTROY) {
	    System.exit(0);
	}
	return false;
    }

    public static void main(String args[]) {
	Frame f = new Frame("Velocity");
	Velocity	velocity = new Velocity();

	velocity.init();
	velocity.start();

	f.add("Center", velocity);
	f.resize(300, 300);
	f.show();
    }
}


/** 
This provides the label and input/output field for a data item.
There will an instance of this class for each input and output value.
*/
class Element extends Panel {
	TextField 	myField;
	Label		theLabel;
	InputArea 	outerparent;

	Element(InputArea target, double inValue, String elName, Color c) {

		this.outerparent = target;
		setLayout(new GridLayout(1,2,0,0));
		
		theLabel = new Label(elName);
		myField = new TextField(String.valueOf(inValue),10);
		
		myField.setBackground(c);
		add(theLabel);
		add(myField);
	}
	
	public void setValue(double value) {
		myField.setText(String.valueOf(value));
		return;
	}
	
	public double getValue() {
		return (Double.valueOf(myField.getText())).doubleValue();
	}

	public boolean action(Event evt, Object arg) {
		if (evt.target instanceof TextField) {
			this.outerparent.update();
			return true;
		}
		else return false;
	}
}

/** 
This provides a label and popup menu.
*/
class AeroChoice extends Panel {
	InputArea 	outerparent;
	Label		theLabel;
	Choice 	myCmenu;
	String words[] = {"hoods", "bartops", "bar ends", "drops", "aerobars",
		"drafting"};
	double values[] = {0.388, 0.445, 0.420, 0.300, 0.233, 0.200};
	int i, nItems = 6;

	AeroChoice(InputArea target) {

		this.outerparent = target;
		setLayout(new GridLayout(1,2,0,0));
		
		theLabel = new Label("Position");
		
		myCmenu = new Choice();
		for (i=0; i<nItems; i++) myCmenu.addItem(words[i]);
		
		add(theLabel);
		add(myCmenu);
	}
	
	public double getValue() {
		return values[myCmenu.getSelectedIndex()];
	}

	public boolean action(Event evt, Object arg) {
		if (evt.target instanceof Choice) {
			this.outerparent.update();
			return true;
		}
		else return false;
	}
}

/** 
This provides a label and popup menu.
*/
class TireChoice extends Panel {
	InputArea 	outerparent;
	Label		theLabel;
	Choice 	myCmenu;
	String words[] = {"clincher", "tubular", "MTB"};
	double values[] = {0.005, 0.004, 0.012};
	int i, nItems = 3;

	TireChoice(InputArea target) {

		this.outerparent = target;
		setLayout(new GridLayout(1,2,0,0));
		
		theLabel = new Label("Tire type");
		
		myCmenu = new Choice();
		for (i=0; i<nItems; i++) myCmenu.addItem(words[i]);
		
		add(theLabel);
		add(myCmenu);
	}
	
	public double getValue() {
		return values[myCmenu.getSelectedIndex()];
	}

	public boolean action(Event evt, Object arg) {
		if (evt.target instanceof Choice) {
			this.outerparent.update();
			return true;
		}
		else return false;
	}
}

class InputArea extends Panel {
	Velocity outerparent;
	Element	power, weight, bikeweight, grade, wind, distance,
		temperature, elevation, transEff, 
		velocity, time, calories;
	TireChoice	tires;
	AeroChoice	aero;
	Button	doit;
	double	pw, wt, bwt, gr, wd, ds, tmp, elev, tr, rr, CvA;
	double	v, t, c;
	double	density, twt, A2, tres;
	
	

	public InputArea() {
	
		setLayout(new GridLayout(15,1,2,2));
		
		// the inputs:
		power  = new Element(this, 300.0, "Power, watts", Color.white);
		weight = new Element(this, 150.0, "Rider weight, lbs", Color.white);
		bikeweight = new Element(this, 22, "Bike weight, lbs", Color.white);
		grade = new Element(this, 0.0, "Grade, %", Color.white);
		wind  = new Element(this, 0.0, "Head wind, mph", Color.white);
		distance = new Element(this, 20.0, "Distance, miles", Color.white);
		temperature = new Element(this, 70.0, "Temperature, F", Color.white);
		elevation = new Element(this, 0.0, "Elevation, ft", Color.white);
		transEff = new Element(this, 95.0, "Trans. Eff., %", Color.white);
		
		tires = new TireChoice(this);
		aero  = new AeroChoice(this);
		
		// the button:
		doit = new Button("Calculate");
		
		// the outputs:
		velocity = new Element(this, 0.0, "Pred. velocity, mph", Color.pink);
		time = new Element(this, 0.0, "Pred. time, minutes", Color.pink);
		calories = new Element(this, 0.0, "Calories expended", Color.pink);
		
		// add to panel:
		add(power);
		add(weight);
		add(bikeweight);
		add(tires);
		add(aero);
		add(grade);
		add(wind);
		add(distance);
		add(temperature);
		add(elevation);
		add(transEff);
		
		doit.setForeground(Color.blue);
		add(doit);
		
		add(velocity);
		add(time);
		add(calories);

	}
	
	public boolean action(Event evt, Object arg) {
		if (evt.target instanceof Button) {
			update();
			return true;
		}
		else return false;
	}
	
	
	public void update() {
		
		// get values 
		pw = power.getValue();
		wt = weight.getValue();
		bwt = bikeweight.getValue();
		gr = grade.getValue() * 0.01;
		wd = wind.getValue() * 0.44704;  // converted to m/s
		ds = distance.getValue();
		tmp = (temperature.getValue() - 32.0) * 0.5555;  // converted to C
		elev = elevation.getValue() * 0.3048;  // converted to m
		tr = transEff.getValue() * 0.01;
		rr = tires.getValue();
		CvA = aero.getValue();
		
		// intermediate values
		density = (1.293 - 0.00426 * tmp) * Math.exp(-elev / 7000.0);
		twt = 4.4482 * (wt + bwt);  // total weight in newtons
		A2 = 0.5 * CvA * density;  // full air resistance parameter
		tres = twt * (gr + rr); // total resistance from gravity and rolling resistance
		
		// calculate v, t and c
		v = Newton(20, 0.05) / 0.44704;
		if (v > 0.0) t = 60.0*ds/v;
			else t = 0.0;  // don't want any div by zero errors
		c = t/60.0 * (1.4/2.2*wt + pw*4.0) / 1.163;  
			// 1.163 is for converting watt-hours to kilocalories
			// basal metabolism is 1.4 w/kg; energy conversion eff = 0.25

		velocity.setValue(v);
		time.setValue(t);
		calories.setValue(c);
		
	}
	
	public double Newton(double guess, double tol) {
		double vel, vNew, f, fp, tv;
		int i, MAX = 20;
		
		vel = guess;
		
		for (i=1; i<MAX; i++) {
			tv = vel+wd;
			f = vel*(A2*tv*tv + tres) - tr*pw;
			fp = A2*(3.0*vel+wd)*tv+tres;
			vNew = vel - f/fp;
			if (abs(vNew-vel)<tol) return vNew;
			vel = vNew;
		}
		return 0.0;
	}
	
	public double abs(double x) {
		return (x<0.0) ? -x : x;
	}
}	
	
