function [sys,x0,str,ts]=velupdt(t,x,u,flag,dt,vn,ve,vd)
%navigation frame velocity update.

switch flag

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0         
    [sys,x0,str,ts] = mdlInitializeSizes(dt,vn,ve,vd);

  %%%%%%%%%%%%%%%%%%%%%%%%
  % Others  &  Terminate %
  %%%%%%%%%%%%%%%%%%%%%%%%
  case {1,9}
    sys = []; % do nothing

  %%%%%%%%%%%%%%%
  % Update      %
  %%%%%%%%%%%%%%%
  case 2
    sys = mdlUpdate(t,x,u,dt);

  %%%%%%%%%%
  % Output %
  %%%%%%%%%%  
  case 3
    sys = mdlOutputs(t,x,u); 
  %%%%%%%%%%%%%%%
  % Update      %
  %%%%%%%%%%%%%%%
  
  case 4
    sys = mdlGetTimeofNextVarHit(t,x,u,dt);

    
  otherwise
    error(['unhandled flag = ',num2str(flag)]);
    
end

% end velupdt
%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys,x0,str,ts] = mdlInitializeSizes(dt,vn,ve,vd)

   sizes = simsizes;
   sizes.NumContStates  = 0;
   sizes.NumDiscStates  = 3;
   sizes.NumOutputs     = 3;
   sizes.NumInputs      = 10;
   sizes.DirFeedthrough = 0;
   sizes.NumSampleTimes = 1;

   sys = simsizes(sizes);
   str = [];
   x0(1) = vn;
   x0(2) = ve;
   x0(3) = vd;
   ts  = [dt 0];   % sample time: [period, offset]

% end mdlInitializeSizes
%
%=============================================================================
% mdlUpdate
% Compute updates for discrete states.
%=============================================================================
%
function sys = mdlUpdate(t,x,u,dt)
%
% variable mapping to MATLAB states and inputs
% v_n, v_e, v_d = x(1), x(2), x(3)
% dvn, dve, dvd = u(1), u(2), u(3)
% omn, ome, omd = u(4), u(5), u(6)
% con, coe, cod = u(7), u(8), u(9)
% g             = u(10)
%
   ux1 = x(1) + u(1) - x(3)*      u(5) *dt + x(2)*(u(9)+u(6))*dt;
   ux2 = x(2) + u(2) - x(1)*(u(9)+u(6))*dt + x(3)*(u(7)+u(4))*dt;
   ux3 = x(3) + u(3) - x(2)*(u(7)+u(4))*dt + x(1)*      u(5) *dt + u(10)*dt;
   
   x(1) = ux1;
   x(2) = ux2;
   x(3) = ux3;
   
   sys = x;

% end mdlUpdate
%
%=============================================================================
% mdlOutputs
% Return the output vector for the S-function
%=============================================================================
%
function sys = mdlOutputs(t,x,u)

   sys = x;

% end mdlOutputs

%=============================================================================
% mdlGetTimeofNextVarHit
%=============================================================================
function sys = mdlGetTimeofNextVarHit(t,x,u,dt)

   sys = t + dt;
   
% end mdlGetTimeofNextVarHit