# UnrealVoxelSim.Simulation.Api

Engine-independent contracts for deterministic fixed-step simulation. `StandardStepDuration` publicly defines the
standard 20 ms step, while each session carries its configured duration through `StepContext`.

`ITickPipeline` is implemented by a composition root. The simulation engine invokes it once per tick and has no
knowledge of domains, phases, ECS, event pumps, or system order. `IStepper` performs explicit deterministic advancement;
`IPacer` maps host elapsed time and a rational global rate to the same tick operation.
