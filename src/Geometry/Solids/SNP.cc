#include "G4Sphere.hh"
#include "Geometry/Solids/SNP.hh"

SNP::SNP(G4String name,G4double r):G4VSolid(name){
    fActualShape = new G4Sphere(name, 0., r, 0., 2*CLHEP::pi, 0., 2*CLHEP::pi);
};

SNP::~SNP() {
    delete fActualShape;
}

EInside SNP::Inside(const G4ThreeVector& p) const {
    return fActualShape->Inside(p);
}

G4ThreeVector SNP::SurfaceNormal(const G4ThreeVector& p) const {
    return fActualShape->SurfaceNormal(p);
}
G4double SNP::DistanceToIn(const G4ThreeVector& p, const G4ThreeVector& v) const {
    return fActualShape->DistanceToIn(p, v);
}
G4double SNP::DistanceToIn(const G4ThreeVector& p) const {
    return fActualShape->DistanceToIn(p);
}
G4double SNP::DistanceToOut(const G4ThreeVector& p, const G4ThreeVector& v,
                             const G4bool calcNorm, G4bool *validNorm, G4ThreeVector *n) const {
    return fActualShape->DistanceToOut(p, v, calcNorm, validNorm, n);
}
G4double SNP::DistanceToOut(const G4ThreeVector& p) const {
    return fActualShape->DistanceToOut(p);
}
void SNP::ComputeDimensions(G4VPVParameterisation* p, const G4int n, const G4VPhysicalVolume* pRep) {
    fActualShape->ComputeDimensions(p, n, pRep);
}
G4GeometryType SNP::GetEntityType() const {
    return fActualShape->GetEntityType();
}
G4VSolid* SNP::Clone() const {
    return fActualShape->Clone();
}
std::ostream& SNP::StreamInfo(std::ostream& os) const {
    return fActualShape->StreamInfo(os);
}


void SNP::DescribeYourselfTo (G4VGraphicsScene &scene) const {
      return fActualShape->DescribeYourselfTo(scene);
};

G4bool SNP::CalculateExtent (const EAxis pAxis, const G4VoxelLimits &pVoxelLimit, const G4AffineTransform &pTransform, G4double &pMin, G4double &pMax) const {
    return fActualShape->CalculateExtent(pAxis, pVoxelLimit,pTransform,  pMin, pMax);
}; 

G4ThreeVector SNP::GetPointOnSurface () const {
      return fActualShape->GetPointOnSurface();
};

void SNP::BoundingLimits(G4ThreeVector& pMin, G4ThreeVector& pMax) const {
    return fActualShape->BoundingLimits(pMin,pMax);
};