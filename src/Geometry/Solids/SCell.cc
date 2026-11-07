#include "G4Ellipsoid.hh"
#include "Geometry/Solids/SCell.hh"
#include "G4IntersectionSolid.hh"
#include "G4SystemOfUnits.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
#include "G4MultiUnion.hh"


SCell::SCell(G4String name, G4double p1, G4double p2):G4VSolid(name){ 
  G4double koeff = 1.8;
  G4double koeff2 = 1.2;
  G4double koeff3 = 0.8;
  G4Ellipsoid *fMainEll = new G4Ellipsoid("MainEllipsoid",koeff2*p1/2, koeff2*p1/2, koeff*p1/2,-koeff3*p1/2,koeff3*p1/2);
  G4double theta = asin(koeff2*p1*sqrt(1-(koeff3/koeff)*(koeff3/koeff))/(p2*2));
  G4double r= (p1/2>p2*cos(theta))? 0: p2*cos(theta)-koeff3*p1/2;
  G4Sphere *fsp = new G4Sphere("Sp1",r,p2,0,2*CLHEP::pi,0,theta); 
  G4Sphere *fsp2 = new G4Sphere("Sp2",r,p2,0,2*CLHEP::pi,CLHEP::pi-theta,CLHEP::pi); 
  G4MultiUnion *fMultiUnion = new G4MultiUnion(name);
  G4double shift = p2*cos(theta);
  fMultiUnion->AddNode(*fMainEll,G4Transform3D(G4RotationMatrix(),G4ThreeVector(0,0,0)));
  fMultiUnion->AddNode(*fsp,G4Transform3D(G4RotationMatrix(),G4ThreeVector(0,0,koeff3*p1/2-shift+(p1/2)*0.05)));
  fMultiUnion->AddNode(*fsp2,G4Transform3D(G4RotationMatrix(),G4ThreeVector(0,0,-koeff3*p1/2+shift-(p1/2)*0.05)));
  fMultiUnion -> Voxelize();
  fActualShape = fMultiUnion;
  fDimensions.push_back(p1);
  fDimensions.push_back(p2);
};

SCell::~SCell() {
 //   delete fActualShape1;
    delete fActualShape;
}
EInside SCell::Inside(const G4ThreeVector& p) const {
    return fActualShape->Inside(p);
}

G4ThreeVector SCell::SurfaceNormal(const G4ThreeVector& p) const {
    return fActualShape->SurfaceNormal(p);
}

G4double SCell::DistanceToIn(const G4ThreeVector& p, const G4ThreeVector& v) const {
    return fActualShape->DistanceToIn(p, v);
}

G4double SCell::DistanceToIn(const G4ThreeVector& p) const {
    return fActualShape->DistanceToIn(p);
}

G4double SCell::DistanceToOut(const G4ThreeVector& p, const G4ThreeVector& v,
                             const G4bool calcNorm, G4bool *validNorm, G4ThreeVector *n) const {
    return fActualShape->DistanceToOut(p, v, calcNorm, validNorm, n);
}

G4double SCell::DistanceToOut(const G4ThreeVector& p) const {
    return fActualShape->DistanceToOut(p);
}
void SCell::ComputeDimensions(G4VPVParameterisation* p, const G4int n, const G4VPhysicalVolume* pRep) {
    fActualShape->ComputeDimensions(p, n, pRep);
}

G4GeometryType SCell::GetEntityType() const {
    return fActualShape->GetEntityType();
}

G4VSolid* SCell::Clone() const {
    return fActualShape->Clone();
}

std::ostream& SCell::StreamInfo(std::ostream& os) const {
    return fActualShape->StreamInfo(os);
}


void SCell::DescribeYourselfTo (G4VGraphicsScene &scene) const {
      return fActualShape->DescribeYourselfTo(scene);
};

G4bool SCell::CalculateExtent (const EAxis pAxis, const G4VoxelLimits &pVoxelLimit, const G4AffineTransform &pTransform, G4double &pMin, G4double &pMax) const {
      return fActualShape->CalculateExtent(pAxis, pVoxelLimit,pTransform,  pMin, pMax);
}; 

G4ThreeVector SCell::GetPointOnSurface () const {
      return fActualShape->GetPointOnSurface();
};

G4Polyhedron * SCell::CreatePolyhedron () const {
      return fActualShape->CreatePolyhedron();
};

void SCell::BoundingLimits(G4ThreeVector& pMin, G4ThreeVector& pMax) const {
    return fActualShape->BoundingLimits(pMin,pMax);
};


