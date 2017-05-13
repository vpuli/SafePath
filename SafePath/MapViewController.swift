//
//  MapViewController.swift
//  SafePath
//
//  Created by Vineeth Puli on 5/13/17.
//
//

import UIKit
import ArcGIS


class MapViewController: UIViewController {
    @IBOutlet var mapView: AGSMapView!
    var damageTable:AGSServiceFeatureTable!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.mapView.map = AGSMap(basemapType: .imageryWithLabelsVector, latitude: 40.7128, longitude: -74.0059, levelOfDetail: 10)
  
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
        
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
    
    func mapView(mapView: AGSMapView!, didTapAtPoint screen: CGPoint, mapPoint mappoint: AGSPoint!) {
        
        //Add a feature at this point
//        addFeature(mappoint)
    }
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
