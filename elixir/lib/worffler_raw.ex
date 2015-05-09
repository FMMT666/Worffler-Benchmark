defmodule WorfflerRaw do

  def start(in_file_1, in_file_2, out_file) do
    in2 = File.open!(in_file_2, [:read, :raw, :read_ahead])
    out = File.open!(out_file, [:write, :raw, :delayed_write])

    in1 = File.open!(in_file_1, [:read, :raw, :read_ahead])
    process_line(in1, in2, out)
  end

  defp process_line(in1, input, out) do
    case :file.read_line(in1) do
      {:ok, line} ->
        String.rstrip(line, ?\n)
        |> write_raw_entry(input, out)
        process_line(in1, input, out)
      _ ->
    end
  end

  defp write_raw_entry(line, input, out) do
    process_next_line_in_2(line, input, out)
  end

  defp process_next_line_in_2(line, input, out) do
    case :file.read_line(input) do
      {:ok, line2} ->
        :file.write(out, line <> line2)
        process_next_line_in_2(line, input, out)
      _ ->
        {:ok, 0} = :file.position(input, :bof)
    end
  end
end
