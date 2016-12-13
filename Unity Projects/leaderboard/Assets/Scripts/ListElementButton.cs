using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Events;
using UnityEngine.EventSystems;
using System.Collections;

public class ListElementButton : MonoBehaviour {
	public Button button;
	public Text uniNameText;
	public Text pointsText;
	public Image elementBackgroundImage;
 	
	void Start()
	{

	}

	//once in each frame
	void Update()
	{


	}

	//for debugging purpose only
	public void NewThing()
	{
		
		uniNameText.color = Color.white;

	}
	//for debugging purpose only
	public void doDo()
	{

		uniNameText.color = Color.red;

	}


}
