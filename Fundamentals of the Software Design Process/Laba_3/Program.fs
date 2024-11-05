open System.IO
open Microsoft.FSharp.Reflection

    type Equipment(price:int, firm:string) =
            member val Price = 
                    if int price < 0 then
                            failwith("Цена не может быть отрицательной") 
                        else int price with get, set
            member val Company = firm
            member this.PrintPerson() = printfn $"Цена: {this.Price} Компания: {this.Company}"

    type MouseType =
    | Ball
    | Laser

    type Cmouse(parameters: string list) =
        inherit Equipment(int parameters.[2], parameters.[3])
        member val Style = 
            match parameters.[0] with
            | "ball" -> Ball
            | "laser" -> Laser
            | _ -> failwith("Неверный тип мышки")
        member val Count = 
            if int parameters.[1] < 0 then
                   failwith("Количество мышек не может быть отрицательным")
            else int parameters.[1] with get, set
        override this.ToString() =
            sprintf "Тип - %s, Цена - %d, Компания - %s, Тип мыши - %A, Количество кнопок - %d." 
                 (this.GetType().Name) base.Price base.Company this.Style this.Count 

    type KeyboardType =
    | Membrane
    | Domed
    | Capacitive

    type Keyboard(parameters: string list) =
        inherit Equipment(int parameters.[2], parameters.[3])
        member val Style = 
            match parameters.[0] with
            | "membrane" -> Membrane
            | "domed" -> Domed
            | "capacitive" -> Capacitive
            | _ -> failwith("Неверный тип мышки")
        member val Connector = parameters.[1] with get, set
        override this.ToString() =
            sprintf "Тип - %s, Цена - %d, Компания - %s, Тип клавиатуры - %A, Тип разъема - %s." 
                (this.GetType().Name)  base.Price base.Company this.Style this.Connector

    type Monitor(parameters: string list) =
        inherit Equipment(int parameters.[2], parameters.[3])
        member val Height = 
            if int parameters.[0] < 0 then
                failwith("Высота монитора не может быть отрицательной")
            else int parameters.[0] with get, set
        member val Width = 
            if int parameters.[1] < 0 then
                failwith("Ширина монитора не может быть отрицательной")
            else int parameters.[1] with get, set
        override this.ToString() =
            sprintf "Тип - %s, Цена - %d, Компания - %s, Высота - %d, Ширина - %d." 
                (this.GetType().Name) base.Price base.Company this.Height this.Width

    type Node(value: Equipment, next: Node option, prev: Node option) =
        member val value = value with get
        member val Next : Node option = next with get, set
        member val Prev : Node option = prev with get, set

    type CircularLinkedList() =
        let mutable head = None
        let mutable count: int = 0

        member this.Add(offEquipment: Equipment) =
            let node = new Node(offEquipment, None, None)
            match head with
            | None ->
                head <- Some node
                node.Next <- Some node
                node.Prev <- Some node
                count <- count + 1
            | Some h ->
                node.Next <- Some h
                node.Prev <- h.Prev
                h.Prev.Value.Next <- Some node
                h.Prev <- Some node
                count <- count + 1

        member this.Print() =
            let mutable currentNode = head
            while currentNode <> None do
                printfn "%A" currentNode.Value.value
                currentNode <- currentNode.Value.Next
                if currentNode = head then
                    currentNode <- None
            printfn "" 

        member this.rem(parameters: string list) =  
            let mutable currentNode : Node option = head
            let mutable coune_list : int = count    
            while coune_list > 0 do
                for cur in currentNode.Value.value.GetType().GetProperties() do   
                    match cur.Name with   
                    | value when value = parameters.[0] ->
                        if parameters.[0] = "Price" then
                            match parameters.[1] with   
                            | "==" ->   
                                if (cur.GetValue(currentNode.Value.value) :?> int) = int(parameters.[2]) then
                                    this.removeNode currentNode
                            | ">=" ->   
                                if (cur.GetValue(currentNode.Value.value) :?> int) >= int(parameters.[2]) then   
                                    this.removeNode currentNode
                            | "<=" ->   
                                if (cur.GetValue(currentNode.Value.value) :?> int) <= int(parameters.[2]) then   
                                    this.removeNode currentNode
                            | "<" ->   
                                if (cur.GetValue(currentNode.Value.value) :?> int) < int(parameters.[2]) then   
                                    this.removeNode currentNode
                            | ">" ->   
                                if (cur.GetValue(currentNode.Value.value) :?> int) > int(parameters.[2]) then  
                                    this.removeNode currentNode
                            | "!=" ->   
                                if (cur.GetValue(currentNode.Value.value) :?> int) <> int(parameters.[2]) then
                                    this.removeNode currentNode
                            | _ ->   
                                failwith $"Неверное условие: {parameters.[1]}" 
                        elif parameters.[0] = "Company" then 
                            match parameters.[1] with
                                | "==" ->   
                                    if (cur.GetValue(currentNode.Value.value).ToString()) = string(parameters.[2]) then
                                        this.removeNode currentNode
                                | "!=" ->   
                                    if (cur.GetValue(currentNode.Value.value).ToString()) <> string(parameters.[2]) then
                                        this.removeNode currentNode
                                | _ ->   
                                    failwith $"Неверное условие: {parameters.[1]}" 
                        | _ ->   
                            ()   
                currentNode <- currentNode.Value.Next
                coune_list <- coune_list - 1
        

        member this.removeNode (nodeToRemove: Node option) =
            match nodeToRemove with
            | None -> ()
            | Some node ->
                if head.IsSome && head.Value.Next = head then
                    // Удаляем единственный элемент в списке
                    head <- None
                elif head.IsSome then
                    let prevNode = node.Prev.Value
                    let nextNode = node.Next.Value
                    prevNode.Next <- Some nextNode
                    nextNode.Prev <- Some prevNode
                    if head = Some node then
                        head <- Some nextNode
                count <- count - 1

let list = new CircularLinkedList()

let readCommands (fileName: string) =
    let commands = ref []
    use file = new StreamReader(fileName)
    while not file.EndOfStream do
        let line = file.ReadLine()
        let parts : string [] = line.Split([|' '|], System.StringSplitOptions.RemoveEmptyEntries)
        if parts.Length > 0 then
            match parts.[0] with
            | "ADD" -> commands := ("ADD", Array.tail parts |> Array.toList) :: !commands
            | "REM" -> commands := ("REM", Array.tail parts |> Array.toList) :: !commands
            | "PRINT" -> commands := ("PRINT", []) :: !commands
            | _ -> printfn $"Неверная команда: {parts.[0]}" 
    List.rev !commands


let add(parameters: string list) =
    match parameters.[0] with
    | "Cmouse" -> list.Add(new Cmouse(List.tail parameters))
    | "Keyboard" -> list.Add(new Keyboard(List.tail parameters))
    | "Monitor" -> list.Add(new Monitor(List.tail parameters))
    | _ -> printfn $"Неверный тип продукта: {parameters.[0]}"

let executeCommands (commands: (string * string list) list) =
    for cmd in commands do
        match cmd with
        | ("ADD", item) -> add item
        | ("REM", item) -> list.rem(item)
        | ("PRINT", _) -> list.Print()
        | _ -> ()

let fileName = __SOURCE_DIRECTORY__ + "/Commands.txt"
let commands = readCommands fileName
executeCommands commands