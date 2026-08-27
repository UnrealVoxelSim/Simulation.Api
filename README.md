# UnrealVoxelSim.Simulation.Api

Engine-independent contracts for deterministic fixed-step simulation. `StandardStepDuration` publicly defines the
standard 20 ms step, while each session carries its configured duration through `StepContext`.

`ITickPipeline` is implemented by the concrete `Simulation.Pipeline` module. Composition roots inject domain
implementations but cannot choose their order. The simulation engine invokes the pipeline once per tick and has no
knowledge of domains, phases, ECS, event pumps, or system order. `IDecisionUpdater` is the narrow game/scenario decision
phase. `IStepper` performs explicit deterministic advancement; `IPacer` maps host elapsed time and a rational global
rate to the same tick operation.
