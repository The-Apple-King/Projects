#include "SimulationModel.h"

#include "DroneFactory.h"
#include "HelicopterFactory.h"
#include "RobotFactory.h"
#include "HumanFactory.h"
#include "DragonFactory.h"
#include "SimulationDataCollector.h"
#include "Data.h"


SimulationModel::SimulationModel(IController& controller)
    : controller(controller) {
  compFactory = new CompositeFactory();
  AddFactory(new DroneFactory());
  AddFactory(new RobotFactory());
  AddFactory(new HelicopterFactory());
  AddFactory(new HumanFactory());
  AddFactory(new DragonFactory());
  data = SimulationDataCollector::getInstance();
}

SimulationModel::~SimulationModel() {
  // Delete dynamically allocated variables
  for (int i = 0; i < entities.size(); i++) {
    delete entities[i];
  }
  for (int i = 0; i < scheduler.size(); i++) {
    delete scheduler[i];
  }
  delete graph;
  delete compFactory;
}

void SimulationModel::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  std::string name = entity["name"];
  JsonArray position = entity["position"];
  std::cout << name << ": " << position << std::endl;

  IEntity* myNewEntity = compFactory->CreateEntity(entity);
  myNewEntity->SetGraph(graph);

  // Call AddEntity to add it to the view
  controller.AddEntity(*myNewEntity);
  entities.push_back(myNewEntity);
}

/// Schedules a trip for an object in the scene
void SimulationModel::ScheduleTrip(JsonObject& details) {
  // variables to save data for collection
  std::string tripName, droneName, strategy;
  double distance, moneyMade;
  Vector3 startPos, endPos;
  // *****************************************

  std::string name = details["name"];
  tripName = name;
  JsonArray start = details["start"];
  JsonArray end = details["end"];
  std::cout << name << ": " << start << " --> " << end << std::endl;

  for (auto entity : entities) {  // Add the entity to the scheduler
    JsonObject detailsTemp = entity->GetDetails();
    std::string nameTemp = detailsTemp["name"];
    std::string typeTemp = detailsTemp["type"];
    if (name.compare(nameTemp) == 0 && typeTemp.compare("robot") == 0 &&
        entity->GetAvailability()) {
      std::string strategyName = details["search"];
      entity->SetDestination(Vector3(end[0], end[1], end[2]));
      entity->SetStrategyName(strategyName);
      scheduler.push_back(entity);

      // collect data **************************
      strategy = strategyName;
      startPos = entity->GetPosition();
      endPos = Vector3(end[0], end[1], end[2]);
      distance = startPos.Distance(endPos);
      droneName = "TEMP NAME";
      std::string detai = "details";
      std::string detail = "detail";
      // moneymade needs a formula***********
      Data *trip = new Data(droneName, tripName, startPos, endPos, distance, strategy,  distance, detail);
      data->collectData(trip);
      // ******************************************
      dynamic_cast<Robot *>(entity)->setData(trip);
      break;
    }
  }
  controller.SendEventToView("TripScheduled", details);
}

/// Updates the simulation
void SimulationModel::Update(double dt) {
  for (int i = 0; i < entities.size(); i++) {
    entities[i]->Update(dt, scheduler);
    controller.UpdateEntity(*entities[i]);
  }
}

void SimulationModel::AddFactory(IEntityFactory* factory) {
  compFactory->AddFactory(factory);
}

void SimulationModel::printData() {
  data->outputDataToCSV("output.csv");
}
