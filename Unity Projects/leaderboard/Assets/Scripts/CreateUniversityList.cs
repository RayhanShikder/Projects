using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System;
using System.Linq;


[System.Serializable]
public class Item{
	public Sprite backGroundImage;
	public string uniName;
	public int uniPoints;
	
	public Button.ButtonClickedEvent changeTextcolor;

	public Item(Sprite img, string uName, int uPoints)
	{
		this.backGroundImage = img;
		this.uniName = uName;
		this.uniPoints = uPoints;
	}
	public Item(string uName, int uPoints)
	{
		this.uniName = uName;
		this.uniPoints = uPoints;
	}
	public void setBackground (Sprite img)
	{
		this.backGroundImage = img;
	}
}


public class CreateUniversityList : MonoBehaviour {

	public GameObject ListElementButton;
	public List<Item> itemList;
	public Transform contentPanel;


	// Use this for initialization
	void Start () {
		CreateList ();
	}

	//create the list of the scroll list element
	void CreateList()
	{

		readCSV ();//read the csv file containing university list with points

		foreach (var item in itemList) 
		{
			GameObject newElement = Instantiate (ListElementButton) as GameObject;
			ListElementButton sampleElement = newElement.GetComponent <ListElementButton>();
			sampleElement.elementBackgroundImage.sprite = item.backGroundImage;
			sampleElement.uniNameText.text = item.uniName.ToString();
			sampleElement.pointsText.text = item.uniPoints.ToString();

			newElement.transform.SetParent(contentPanel);
		}
	}

	void readCSV()
	{

		GameObject back1 = new GameObject();
		SpriteRenderer renderer1 = back1.AddComponent<SpriteRenderer>();
		
		renderer1.sprite = Resources.Load("black_row", typeof(Sprite)) as Sprite;//black_row  image
		
		GameObject back2 = new GameObject();
		SpriteRenderer renderer2 = back2.AddComponent<SpriteRenderer>();
		
		renderer2.sprite = Resources.Load("gray_row", typeof(Sprite)) as Sprite;//gray_row image

		var reader = new StreamReader(File.OpenRead("Assets/Resources/UniList.csv"));

		//read the university list from the csv file line by line
		while(!reader.EndOfStream)
		{
			var line = reader.ReadLine();
			var values = line.Split(',');
			Item tempItem;
			tempItem = new Item(values[0],Int32.Parse(values[1]));
			itemList.Add (tempItem);
		}

		//sort the list according to points. if two item has same points then sort lexicographically
		itemList.Sort(
			delegate(Item p1, Item p2)
			{
				int compare=p2.uniPoints.CompareTo(p1.uniPoints);
				if(compare == 0)
				return p1.uniName.CompareTo(p2.uniName);
				return compare;
			}
		);

		//set the background image accordingly
		for (int i=0; i<itemList.Count; i++) {
			if(i%2==0)itemList[i].setBackground(renderer1.sprite);
			else itemList[i].setBackground(renderer2.sprite);
		}


	}
	// Update is called once per frame
	void Update () {
	
	}

	//for debugging purpose only
	public void doSomething()
	{
		Debug.Log ("Hellooooo");
	}
}
