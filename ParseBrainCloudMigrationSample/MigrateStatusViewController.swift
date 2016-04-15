//
//  DetailViewController.swift
//  parseBrainSample
//
//  Created by Mario Couture on 2016-03-09.
//  Copyright © 2016 bitHeads inc. All rights reserved.
//

import Foundation
import UIKit

class MigrateStatusViewController: UIViewController {
    
    @IBOutlet weak var loggedinToField: UILabel!
    @IBOutlet weak var authneticatingToBCField: UILabel!
    @IBOutlet weak var migratingToBCField: UILabel!
    @IBOutlet weak var readyField: UILabel!
    
    override func viewDidAppear(animated: Bool) {
        self.loggedinToField.text = "Authenticating..."
        self.authneticatingToBCField.text = ""
        self.migratingToBCField.text = ""
        self.readyField.text = ""        
    }
    
}