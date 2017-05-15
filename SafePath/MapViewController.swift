//
//  MapViewController.swift
//  SafePath
//
//  Created by Vineeth Puli on 5/13/17.
//
//

import SwiftyJSON
import UIKit
import ArcGIS
import PubNub

class MapViewController: UIViewController {
    @IBOutlet var mapView: AGSMapView!

    var routeTask : AGSRouteTask!
    
    private var graphicsOverlay = AGSGraphicsOverlay()
    let appDelegate = UIApplication.shared.delegate as! AppDelegate
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let pubclient = appDelegate.client
        self.text(client: pubclient!, number: "17326628487", message2: "You are an idiot")
        // PubNub.client(self).text("7326628487", "Your a neck");
     //   let appDelegate = UIApplication.shared.delegate as! AppDelegate
    //  let pubclient = appDelegate.client
        //pubclient.text("7326628487","Your a neck");
        
        var jsonData: Data?
        
        if let file = Bundle.main.path(forResource: "qb7u-rbmr", ofType: "json") {
            print("success")
            jsonData = try? Data(contentsOf: URL(fileURLWithPath: file))
        } else {
            print("Fail")
        }
       
     
        do {
            
            let jsonObject = try JSONSerialization.jsonObject(with: jsonData!, options: .allowFragments) as? [[String: AnyObject]]
            let jsonString = String(data: jsonData!, encoding: .utf8)
            
            
            
        } catch let error as NSError {
            print(error)
        }
        
        
        
        
        //initialize map with basemap
        let map = AGSMap(basemap: AGSBasemap.imageryWithLabels())
        
        /*
        self.mapView.map = AGSMap(basemapType: .imageryWithLabelsVector, latitude: 40.7128, longitude: -74.0059, levelOfDetail: 10)
        */
        
       
        //initial viewpoint
        var longitude : CLLocationDegrees
        var latitude : CLLocationDegrees
        latitude = 40.7128
        longitude = -74.00059
        var location = CLLocationCoordinate2D.init()
        location.latitude = latitude
        location.longitude = longitude
        let center = AGSPoint(clLocationCoordinate2D: location)
       
        //change scale for zoom
        map.initialViewpoint = AGSViewpoint(center: center, scale: 6500)
        
        //assign map to the map view
        self.mapView.map = map
        
        //add graphics overlay to the map view
        self.mapView.graphicsOverlays.add(graphicsOverlay)
        
        //add a graphic with simple marker symbol
        self.addSimpleMarkerSymbol(lat: 40.7128, lon: -74.00059)
        //add latitude and longitude arguments
    
        let json1 = try? JSON(data: jsonData!)
        
  
         for element in (json1?.array)! {
            let latstring = element["latitude"].stringValue
            let latvalue = (latstring as NSString).doubleValue
            let longstring = element["longitude"].stringValue
            let longvalue = (longstring as NSString).doubleValue
         
            self.addSimpleMarkerSymbol(lat: latvalue, lon: longvalue)
         
         }
 
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
        
    }
  
    /*
    func parseJSON{
        
        
    }
  */
    
    func addSimpleMarkerSymbol(lat: Double, lon: Double) {
        //create a simple marker symbol
        let symbol = AGSSimpleMarkerSymbol(style: .circle, color: UIColor.red.withAlphaComponent(0.3), size: 12)
        
        
        
        var longitude : CLLocationDegrees
        var latitude : CLLocationDegrees
        latitude = lat
        longitude = lon
        var location = CLLocationCoordinate2D.init()
        location.latitude = latitude
        location.longitude = longitude
        
        //create point
        let point = AGSPoint(clLocationCoordinate2D: location)
        
        //graphic for point using simple marker symbol
        let graphic = AGSGraphic(geometry: point, symbol: symbol, attributes: nil)
        
        //add the graphic to the graphics overlay
        self.graphicsOverlay.graphics.add(graphic)
        
        print("point added")
    }
    
    func text(client: PubNub, number: String, message2: String){
       let stringList = [number, message2];
        client.publish().message(stringList).channel("sendclick-text")
            .shouldStore(true)
        print("published")
        
        
                    
    }

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
/*
    func mapView(mapView: AGSMapView!, didTapAtPoint screen: CGPoint, mapPoint mappoint: AGSPoint!) {
        
        //Add a feature at this point
        //addFeature(mappoint)
    }
    */
/*
     
    func addFeature(point: AGSPoint!) {
        
        //Create attributes for the feature
        var attributes = Dictionary<String,NSObject>()
        attributes["typdamage"] = "Minor" as NSObject
        attributes["primcause"] = "Earthquake" as NSObject
        
        //Create a new feature from the attributes and the point
        let feature = self.damageTable.createFeature(attributes: attributes, geometry: point)
        
        //Add the new feature
        self.damageTable.add(feature) { [weak self] (error: Error?) -> Void in
            if let error = error {
                print("Error while adding feature :: \(error.localizedDescription)")
            }
            else {
                //applied edits on success
                
            }
            //enable interaction with map view
            self?.mapView.isUserInteractionEnabled = true
        }
    }
*/
    
}
